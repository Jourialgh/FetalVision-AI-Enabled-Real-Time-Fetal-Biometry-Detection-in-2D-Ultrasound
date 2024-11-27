import unittest
import os
import torch
import cv2
import sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from model.YOLOv7Detector import YOLOv7Detector


class TestYOLOv7Detection(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        """
        Setup for the test class, load the YOLOv7 model.
        """
        
        weights_path = os.path.join(os.path.dirname(__file__),'..','model', 'best.pt')
        cls.model = YOLOv7Detector(weights_path)

    def test_load_model(self):
        """Test if the YOLOv7 model loads correctly."""
        self.assertIsNotNone(self.model.model, "Model failed to load.")

    def test_postprocessing(self):
        """Test the postprocessing of predictions."""
        image_path = os.path.join(os.path.dirname(__file__), '/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/image.png')
        tensor, orig_img = self.model.preprocess_image(image_path)

        # Mock prediction: [x1, y1, x2, y2, confidence, class]
        predictions = [[100, 100, 200, 200, 0.8, 1]]   

        processed_img, measurements = self.model.postprocess_predictions(predictions, orig_img)

        self.assertIsInstance(measurements, list, "Postprocessing should return a list of measurements.")
        self.assertGreater(len(measurements), 0, "There should be at least one detection.")
        self.assertIn('femur_length_mm', measurements[0], "The measurements should contain 'femur_length_mm'.")

       
        self.assertEqual(processed_img[100, 100, 1], 255, "Bounding box should be drawn at the correct position.")

    def test_image_detection(self):
        """Test the detection on a sample image."""
        image_path = os.path.join(os.path.dirname(__file__), '/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/image.png')

        # Run detection
        output_img = self.model.detect_image(image_path)

       
        self.assertIsNotNone(output_img, "Detection failed, no output image returned.")

        
        found_bboxes = False
        for row in output_img:
            if (row == [0, 255, 0]).any():  
                found_bboxes = True
                break

        self.assertTrue(found_bboxes, "No bounding boxes detected on the image.")

    def test_inference_flow(self):
        """Test the full inference flow from image upload to detection and postprocessing."""
        image_path = os.path.join(os.path.dirname(__file__), '/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/image.png')

        # Run full detection flow
        output_img, measurements = self.model.detect_image(image_path)

        # Check if the detection result is valid
        self.assertIsNotNone(output_img, "Inference failed, no output image returned.")
        self.assertGreater(len(measurements), 0, "No measurements found from the detections.")
        
        
        found_bboxes = False
        for row in output_img:
            if (row == [0, 255, 0]).any():  # Look for bounding box color (green)
                found_bboxes = True
                break

        self.assertTrue(found_bboxes, "No bounding boxes detected on the output image.")

        # Save the output image to disk
        output_img_path = 'output_detection_image.png'
        cv2.imwrite(output_img_path, output_img)
        print(f"Output image saved to: {output_img_path}")

      # display results
        cv2.imshow("Output Image", output_img)
        cv2.waitKey(0)  # Wait for a key press to close the window
        cv2.destroyAllWindows()  # Close the OpenCV window

    @classmethod
    def tearDownClass(cls):
        """Cleanup after tests (if necessary)."""
        pass


if __name__ == '__main__':
    unittest.main()
