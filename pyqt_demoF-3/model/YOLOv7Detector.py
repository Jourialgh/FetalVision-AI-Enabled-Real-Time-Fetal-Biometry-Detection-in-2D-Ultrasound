import sys
import os
import torch
import cv2
import numpy as np

# the path for YOLOv7
sys.path.append(os.path.join(os.path.dirname(__file__), "yolov7"))

# Import necessary modules from the YOLOv7 repository
from model.yolov7.models.experimental import attempt_load
from model.yolov7.utils.general import check_img_size, non_max_suppression
from model.yolov7.utils.torch_utils import select_device

class YOLOv7Detector:
    """
    Class responsible for loading the YOLOv7 model, preprocessing input images,
    running detections, and postprocessing results.
    """
    def __init__(self, weights_path):
        self.device = select_device("")  
        self.model = self.load_yolov7_model(weights_path)

    def load_yolov7_model(self, weights_path):
        """
        Loads the YOLOv7 model with the specified weights.
        """
        model = attempt_load(weights_path, map_location=self.device)  # Load the model
        model.eval()  # Set model to evaluation mode
        return model

    def preprocess_image(self, image_path, img_size=640):
        """
        Preprocesses the input image:
        - Loads image from file
        - Resizes to `img_size`
        - Normalizes pixel values to [0, 1] range
        """
        img = cv2.imread(image_path)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

        # Resize the image to exactly 640x640 (no padding or aspect ratio handling)
        img_resized = cv2.resize(img, (img_size, img_size))  # Resize the image to 640x640
        
        tensor = torch.from_numpy(img_resized).permute(2, 0, 1).float() / 255.0
        return tensor.unsqueeze(0).to(self.device), img_resized, img  # Return both resized and original image

    def postprocess_predictions(self, predictions, orig_img, orig_img_resized, conf_threshold=0.3, scale_factor=0.4, ignore_classes=None):
        """
        Postprocesses the predictions:
        - Filters detections based on confidence threshold
        - Draws bounding boxes on the original image
        - Extracts measurement data (e.g., class, confidence, bounding box size)
        - Converts bounding box size to centimeters using scale_factor
        - Ignores specific classes (e.g., head circumference)
        """
        if ignore_classes is None:
            ignore_classes = []  # Default to an empty list if no classes are specified to ignore
        
        h_resized, w_resized, _ = orig_img_resized.shape
        h, w, _ = orig_img.shape  # Original image dimensions
        measurements = []  # List to store the extracted measurement data

        if predictions is None or len(predictions) == 0:
            return orig_img, measurements  # No predictions, return the original image

        for pred in predictions:
            if pred is None or len(pred) == 0:  # Skip empty predictions
                continue

            if len(pred.shape) == 1:
                pred = pred[None, :]  # Reshape it to 2D (1, N)

            boxes = pred[:, :-2]  # Get box coordinates
            conf = pred[:, -2]  # Confidence
            cls = pred[:, -1]  # Class

            for box, confidence, class_id in zip(boxes, conf, cls):
                if confidence > conf_threshold:  # Only process predictions with confidence > threshold
                    if class_id in ignore_classes:
                        continue  # Skip this class (e.g., head circumference)

                    x1, y1, x2, y2 = map(int, box)

                    # Scale bounding box coordinates based on original image size
                    x1 = int(x1 * (w / w_resized))
                    y1 = int(y1 * (h / h_resized))
                    x2 = int(x2 * (w / w_resized))
                    y2 = int(y2 * (h / h_resized))

                    # Debug: Print raw bounding box values and confidence
                    print(f"Bounding Box: {(x1, y1, x2, y2)}, Confidence: {confidence:.2f}")
                    
                    # Draw the bounding box on the image
                    cv2.rectangle(orig_img, (x1, y1), (x2, y2), (0, 255, 0), 2)

                    # Calculate bounding box height (in pixels)
                    bbox_height = y2 - y1
                    print(f"Bounding Box Height (in pixels): {bbox_height}")

                    # Convert bbox height from pixels to centimeters (divide by 10 for cm)
                    femur_length_cm = (bbox_height * scale_factor) / 10  # Conversion to cm
                    print(f"Femur Length in cm (before correction): {femur_length_cm:.2f}")

                    # Now we can safely create the label
                    label = f"Femur Length: {femur_length_cm:.2f} cm"

                    # Append the results to the measurements list
                    measurements.append({
                        'class': int(class_id),
                        'confidence': confidence,
                        'bbox': (x1, y1, x2, y2),
                        'femur_length_cm': femur_length_cm  # Add femur length in cm
                    })

                    # Adjusted font size for label
                    font = cv2.FONT_HERSHEY_SIMPLEX
                    font_scale = 0.5
                    font_thickness = 1

                    (text_width, text_height), baseline = cv2.getTextSize(label, font, font_scale, font_thickness)

                    # Create a background rectangle to place the text on
                    cv2.rectangle(orig_img, (x1, y1 - text_height - 10), (x1 + text_width, y1), (0, 255, 0), -1)
                    # Put the text on top of the background rectangle
                    cv2.putText(orig_img, label, (x1, y1 - 5), font, font_scale, (0, 0, 0), font_thickness, lineType=cv2.LINE_AA)

        return orig_img, measurements


    def detect_image(self, image_path, conf_threshold=0.3, ignore_classes=None):
        """
        Detects objects in an image using the YOLOv7 model.
        """
        input_tensor, orig_img_resized, orig_img = self.preprocess_image(image_path)
        with torch.no_grad():
            predictions = self.model(input_tensor)[0]
            print("Raw Predictions:", predictions)
            predictions = non_max_suppression(predictions, conf_threshold, 0.4)  # Apply NMS with IoU threshold of 0.4
            predictions = predictions[0].cpu().numpy()  # Convert to NumPy for postprocessing
        output_img, measurements = self.postprocess_predictions(predictions, orig_img, orig_img_resized, conf_threshold, ignore_classes=ignore_classes)
        return output_img, measurements

