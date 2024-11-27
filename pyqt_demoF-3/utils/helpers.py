import cv2
import numpy as np
import math

# Helper Functions
def preprocess_image_for_display(img):
    """Ensure the image fits properly in the display box"""
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

def preprocessing(img_path):
    """Load and preprocess the image for model prediction"""
    img = cv2.imread(img_path, 0)
    img = cv2.resize(img, (256, 256))
    img = np.expand_dims(img, axis=2)
    img = img / 256
    return img

def prediction(img, model):
    """Make a prediction using the model and process the output"""
    img = np.expand_dims(img, 0)
    print(model.predict(img))
    prediction = (model.predict(img)[0, :, :, :] > 0.1).astype(np.uint8)
    img = (prediction * 255).astype(np.uint8)
    return img

def final_preprocessing(output_img, input_img):
    """Perform final preprocessing steps and calculate measurements"""
    pixel_to_cm = 0.02  # Example conversion factor
    kernel = np.ones((5, 5), np.uint8)

    # Image processing pipeline
    blurred = cv2.GaussianBlur(output_img, (5, 5), 0)
    _, thresholded = cv2.threshold(blurred, 127, 255, cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresholded, kernel, iterations=3)
    eroded = cv2.erode(dilated, kernel, iterations=2)
    img = np.expand_dims(eroded, 2)

    # Contour detection
    contours, _ = cv2.findContours(eroded, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    measurements = {"HC": 0, "BPD": 0, "OFD": 0}

    input_img_display = (input_img * 255).astype(np.uint8)
    input_img_display = cv2.cvtColor(input_img_display, cv2.COLOR_GRAY2BGR)
    black_img = np.zeros(input_img_display.shape, np.uint8)
    output_with_ellipse = input_img_display.copy()

    if contours:
        # Select the largest contour
        contour = max(contours, key=cv2.contourArea)
        if len(contour) >= 5:
            # Fit an ellipse to the largest contour
            ellipse = cv2.fitEllipse(contour)
            center, axes, angle = ellipse
            major_axis = max(axes)
            minor_axis = min(axes)

            # Calculate measurements
            a = major_axis / 2.0
            b = minor_axis / 2.0
            circumference_pixels = math.pi * (3 * (a + b) - math.sqrt((3 * a + b) * (a + 3 * b)))
            measurements["HC"] = round(circumference_pixels * pixel_to_cm, 2)
            measurements["BPD"] = round(minor_axis * pixel_to_cm, 2)
            measurements["OFD"] = round(major_axis * pixel_to_cm, 2)

            # Draw the ellipse and measurements
            cv2.ellipse(black_img, ellipse, (255, 255, 255), 2)
            cv2.ellipse(output_with_ellipse, ellipse, (46, 204, 113), 2)

            # Draw axes
            center = tuple(map(int, center))
            major_vector = (int(a * math.cos(math.radians(angle))),
                            int(a * math.sin(math.radians(angle))))
            minor_vector = (int(b * math.cos(math.radians(angle + 90))),
                            int(b * math.sin(math.radians(angle + 90))))

            # Draw the major (OFD) axis
            cv2.line(output_with_ellipse,
                     (center[0] - major_vector[0], center[1] - major_vector[1]),
                     (center[0] + major_vector[0], center[1] + major_vector[1]),
                     (231, 76, 60), 2)

            # Draw the minor (BPD) axis
            cv2.line(output_with_ellipse,
                     (center[0] - minor_vector[0], center[1] - minor_vector[1]),
                     (center[0] + minor_vector[0], center[1] + minor_vector[1]),
                     (52, 152, 219), 2)

    # Format the output images for display
    input_img_display = preprocess_image_for_display(input_img_display)
    output_with_ellipse = preprocess_image_for_display(output_with_ellipse)

    return (
        input_img_display,
        output_with_ellipse,
        f"HC: {measurements['HC']} cm",
        f"BPD: {measurements['BPD']} cm",
        f"OFD: {measurements['OFD']} cm"
    )
