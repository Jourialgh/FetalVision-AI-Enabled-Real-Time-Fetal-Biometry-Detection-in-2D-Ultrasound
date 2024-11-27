import unittest
import os
import cv2
import sys
import numpy as np
from PyQt5.QtWidgets import QApplication, QMainWindow,QFileDialog
from PyQt5.QtTest import QTest
from PyQt5.QtCore import Qt
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
 
from model.UNnetModel import UNetModel
from main import UploadWindow  


class TestUNetModel(unittest.TestCase):
    def setUp(self):
        """Set up the U-Net model instance for the tests."""
        self.model_path = os.path.join(os.path.dirname(__file__), "..","model","u_net_model_v2.h5")
        self.unet_model = UNetModel(self.model_path)

    # def test_model_loading(self):
    #     """Test if the U-Net model is loaded correctly."""
    #     self.assertIsNotNone(self.unet_model.model, "U-Net model should be loaded.")

    # def test_preprocessing(self):
    #     """Test if image preprocessing works correctly."""
    #     test_image_path = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/053_HC.png"# Replace with a valid path
    #     preprocessed_img = self.unet_model.preprocessing(test_image_path)
    #     self.assertEqual(preprocessed_img.shape, (256, 256, 1), "Image should be resized to (256, 256, 1).")
    #     self.assertTrue(np.all(preprocessed_img <= 1), "Image values should be normalized to [0, 1].")

    # def test_prediction(self):
    #     """Test prediction on a sample image."""
    #     test_image_path = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/test_1_neg.png" # Replace with a valid path
    #     preprocessed_img = self.unet_model.preprocessing(test_image_path)
    #     predicted_img,_ = self.unet_model.prediction(preprocessed_img)
    #     # cv2.imshow(f"{test_image_path}",predicted_img)
    #     # cv2.waitKey(0)
    #     # # closing all open windows
    #     # cv2.destroyAllWindows()
    #     self.assertEqual(predicted_img.shape, (256, 256,1), "Predicted image should have shape (256, 256).")
    #     self.assertTrue(np.all(np.isin(predicted_img, [0, 255])), "Predicted image should be binary (0 or 255).")
    
    # def test_final_preprocessing(self):
    #     """Test the final preprocessing logic."""
    #     test_image_path = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/059_HC.png" # Replace with a valid path
    #     preprocessed_img = self.unet_model.preprocessing(test_image_path)

    #     predicted_img = self.unet_model.prediction(preprocessed_img)
    #     result_img, black_img, measurements = self.unet_model.final_preprocessing(predicted_img,preprocessed_img)
    #     cv2.imshow("result_2",result_img)
    #     cv2.waitKey(0)

    #     # closing all open windows
    #     cv2.destroyAllWindows()
    #     cv2.imshow("result_black",black_img)
    #     cv2.waitKey(0)

    #     # closing all open windows
    #     cv2.destroyAllWindows()
    #     self.assertIsInstance(measurements, dict, "Measurements should be returned as a dictionary.")
    #     self.assertIn("HC", measurements, "Measurements should contain 'HC'.")
    #     self.assertIn("BPD", measurements, "Measurements should contain 'BPD'.")
    #     self.assertIn("OFD", measurements, "Measurements should contain 'OFD'.")

    # def test_invalid_image(self):
    #     """Test invalid or corrupted image file."""
    #     invalid_image_path = ".\photo_2023-06-29_22-19-31.jpg"  # Replace with a non-existent or invalid path
    #     result_img, measurements = self.unet_model.process_image(invalid_image_path)
    #     self.assertIsNone(result_img, "Result image should be None for invalid input.")
    #     self.assertEqual(measurements["HC"], "Error", "Measurements should indicate an error for invalid input.")
    # def test_no_objects_detected(self):
    #     """Test the case where no objects are detected in the image."""
    #     no_objects_image = "/Users/shadanyousef/Desktop/pyqt_demoF-3/testing/test_2_neg.png"  # Replace with an image guaranteed to have no objects
    #     result_img, measurements = self.unet_model.process_image(no_objects_image)
    #     self.assertGreaterEqual(measurements["HC"],1, "HC should be 1 when no objects are detected.")
    #     self.assertGreaterEqual(measurements["BPD"], 1, "BPD should be 1 when no objects are detected.")
    #     self.assertGreaterEqual(measurements["OFD"], 1, "OFD should be 1 when no objects are detected.")

    
    def test_run_unet_detection(self):
        """Test integration with the HC UI and UNET detection (Interactive Test)."""

        # Initialize the QApplication and window
        app = QApplication([])  # Start the PyQt5 application
        window = QMainWindow()  # Create a main window instance

        # Create the UploadWindow instance
        upload_window = UploadWindow(window)
        upload_window.show()

        # Activate the HC (Fetal Length) window section if it's separate
        # (For example, let's assume your UploadWindow class has a method to open the HC upload section)
        upload_window.switchToUploadHCPage()  # Ensure the HC window is shown (modify this based on your actual method)

        # Now, the application is running and will wait for user interaction
        print("Please click the 'Upload' button in the HC window and select an image manually.")
        upload_window.uploadFileForHC()
        app.exec_()  # This will start the application and show the HC window
        # After selecting the image manually, the following checks will run:
        self.assertIsNotNone(upload_window.uploadedHCImage_label.pixmap(), "Output image is not displayed in the QLabel.")
        self.assertNotEqual(upload_window.mHC_label2.text(), "", "Measurement data is not updated.")
        self.assertNotEqual(upload_window.mBPD_label.text(), "", "Measurement data is not updated.")
        self.assertNotEqual(upload_window.mOFD_label.text(), "", "Measurement data is not updated.")
        # Quit the application after the test
        app.quit() # Quit the application after the test
  
if __name__ == '__main__':
    unittest.main()
