import cv2
import numpy as np
import math
from tensorflow.keras.models import load_model
class UNetModel:
    def __init__(self, model_path="u_net_model_v2.h5"):
        """Initialize the UNetModelHandler with a trained model."""
        self.model = load_model(model_path)

    def preprocess_image_for_display(self, img):
        """Ensure the image fits properly in the display box."""
        if len(img.shape) == 2:
            img = cv2.cvtColor(img, cv2.COLOR_GRAY2RGB)
        elif len(img.shape) == 3 and img.shape[2] == 1:
            img = cv2.cvtColor(img, cv2.COLOR_GRAY2RGB)

        max_size = 800
        height, width = img.shape[:2]
        if height > max_size or width > max_size:
            ratio = min(max_size / width, max_size / height)
            new_size = (int(width * ratio), int(height * ratio))
            img = cv2.resize(img, new_size, interpolation=cv2.INTER_AREA)

        return img

    def preprocessing(self, img_path):
        """Preprocess the input image for the UNet model."""
        img = cv2.imread(img_path, 0)
        img = cv2.resize(img, (256, 256))
        img = np.expand_dims(img, axis=2)
        img = img / 256.0
        return img

    def prediction(self, img):
        """Predict using the UNet model."""
        img = np.expand_dims(img, 0)
        prediction = (self.model.predict(img)[0, :, :, :] > 0.1).astype(np.uint8)
        img = (prediction * 255).astype(np.uint8)
        return img

    def final_preprocessing(self, output_img, input_img, pixel_to_cm=0.02):
        """Post-process the model output and calculate measurements."""
        kernel = np.ones((5, 5), np.uint8)
        blurred = cv2.GaussianBlur(output_img, (5, 5), 0)
        _, thresholded = cv2.threshold(blurred, 127, 255, cv2.THRESH_BINARY)
        dilated = cv2.dilate(thresholded, kernel, iterations=3)
        eroded = cv2.erode(dilated, kernel, iterations=2)
        img = np.expand_dims(eroded, axis=-1)

        _, thresholded = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
        contours, hierarchy = cv2.findContours(thresholded, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        input_img = (input_img * 255).astype(np.uint8)
        input_img = cv2.cvtColor(input_img, cv2.COLOR_GRAY2BGR)
        black_img = np.zeros(input_img.shape, np.uint8)

        measurements = {"HC": 0, "BPD": 0, "OFD": 0}

        if contours:
            contour = max(contours, key=cv2.contourArea)
            if len(contour) >= 5:
                ellipse = cv2.fitEllipse(contour)
                center, axes, angle = ellipse

                major_axis = max(axes)
                minor_axis = min(axes)
                a, b = major_axis / 2.0, minor_axis / 2.0

                circumference_pixels = math.pi * (3 * (a + b) - math.sqrt((3 * a + b) * (a + 3 * b)))

                measurements["HC"] = round(circumference_pixels * pixel_to_cm, 2)
                measurements["BPD"] = round(minor_axis * pixel_to_cm, 2)
                measurements["OFD"] = round(major_axis * pixel_to_cm, 2)

                cv2.ellipse(black_img, ellipse, (255, 255, 255), 2)
                cv2.ellipse(input_img, ellipse, (46, 204, 113), 2)
                  # Calculate major and minor axis vectors
                major_axis_vector = (int(math.cos(math.radians(angle)) * a), int(math.sin(math.radians(angle)) * a))
                minor_axis_vector = (int(-math.sin(math.radians(angle)) * b), int(math.cos(math.radians(angle)) * b))

                # Draw major axis (red line)
                cv2.line(input_img,
                        (int(center[0] - major_axis_vector[0]), int(center[1] - major_axis_vector[1])),
                        (int(center[0] + major_axis_vector[0]), int(center[1] + major_axis_vector[1])),
                        (231, 76, 60), 2)

                # Draw minor axis (blue line)
                cv2.line(input_img,
                        (int(center[0] - minor_axis_vector[0]), int(center[1] - minor_axis_vector[1])),
                        (int(center[0] + minor_axis_vector[0]), int(center[1] + minor_axis_vector[1])),
                        (52, 152, 219), 2)
        return input_img, black_img, measurements

    def process_image(self, img_path):
        """Process an input image end-to-end."""
        try:
            processed_img = self.preprocessing(img_path)
            output_img = self.prediction(processed_img)
            result_img, measurements = self.final_preprocessing(output_img, processed_img)
            return result_img, measurements
        except Exception as e:
            print(f"Error in process_image: {e}")
            return None, {"HC": "Error", "BPD": "Error", "OFD": "Error"}