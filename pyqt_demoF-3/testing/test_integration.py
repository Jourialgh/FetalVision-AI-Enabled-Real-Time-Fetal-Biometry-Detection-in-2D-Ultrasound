import unittest
import os
from PyQt5.QtWidgets import QApplication, QMainWindow,QFileDialog
from PyQt5.QtTest import QTest
from PyQt5.QtCore import Qt
from unittest.mock import patch
import sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from main import UploadWindow
from model.YOLOv7Detector import YOLOv7Detector

class test_integration(unittest.TestCase):
    def setUp(self):
        """Set up the YOLOv7 detector instance for the tests."""
        self.weights_path = os.path.join(os.path.dirname(__file__), "..","model","best.pt")
        self.detector = YOLOv7Detector(self.weights_path)

    def test_model_loading(self):
        """Test if the YOLOv7 model is loaded correctly."""
        self.assertIsNotNone(self.detector.model, "YOLOv7 model should be loaded.")


    def test_detection(self):
        """Test detection on a sample image."""
        test_image_path = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/image.png"
        output_img = self.detector.detect_image(test_image_path)
        self.assertIsNotNone(output_img, "Detection should return an image with bounding boxes.")

    def test_invalid_image(self):
        """Test invalid or corrupted image file."""
        invalid_image_path = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/image004.jpg"
        try:
            self.detector.detect_image(invalid_image_path)
        except Exception as e:
            self.assertTrue(str(e).startswith("Error"), "Invalid image should trigger an error")

    def test_no_objects_detected(self):
        """Test the case where no objects are detected in the image."""
        no_objects_image = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/images.png"
        
        # Perform detection
        output_img, measurements = self.detector.detect_image(no_objects_image)
        
        # Check if no objects were detected 
        self.assertEqual(len(measurements), 0, "No objects should be detected in this image.")
        
    def test_batch_processing(self):
        """Test running detection on multiple images."""
        images = [
            "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/image.png",
            "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/femur.png",
            "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/Longitudinal-sonogram-of-the-fetal-femur-length.ppm-2.png"
        ]
        for image_path in images:
            try:
                output_img = self.detector.detect_image(image_path)
                self.assertIsNotNone(output_img, f"Failed to process image: {image_path}")
            except Exception as e:
                self.fail(f"Error processing image {image_path}: {e}")

    def test_run_yolov7_detection(self):
        """Test integration with the FL UI and YOLOv7 detection (Interactive Test)."""

        # Initialize the QApplication and window
        app = QApplication([])  # Start the PyQt5 application
        window = QMainWindow()  # Create a main window instance

        # Create the UploadWindow instance
        upload_window = UploadWindow(window)
        upload_window.show()

        # Activate the FL (Fetal Length) window section if it's separate
        # (For example, let's assume your `UploadWindow` class has a method to open the FL upload section)
        upload_window.switchToUploadFLPage()  # Ensure the FL window is shown (modify this based on your actual method)

       
        print("Please click the 'Upload' button in the FL window and select an image manually.")
        app.exec_()  

        # After selecting the image manually, the following checks will run:
        self.assertIsNotNone(upload_window.FL_outputIMG.pixmap(), "Output image is not displayed in the QLabel.")
        self.assertNotEqual(upload_window.mFL_label2.text(), "", "Measurement data is not updated.")

        # Quit the application after the test
        app.quit() # Quit the application after the test



if __name__ == '__main__':
    unittest.main()
