import sys
import os
import torch
import cv2
import numpy as np
import sqlite3
import resources_rc
import math
from PyQt5.QtWidgets import QScrollArea

sys.path.append(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(os.path.join(os.path.dirname(__file__), "model", "yolov7"))
from model.YOLOv7Detector import YOLOv7Detector
from model.UNnetModel import UNetModel
from PyQt5.uic import loadUi
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QLabel, QFileDialog, QPushButton, QVBoxLayout, QWidget, QTableWidget, QTableWidgetItem
from PyQt5.QtGui import QFont, QPixmap, QImage
from PyQt5.QtCore import QPropertyAnimation,Qt

 

class MainApp(QMainWindow):
    def __init__(self):
        super(MainApp, self).__init__()
        loadUi(os.path.join(os.path.dirname(__file__), "view" ,"mainwindow.ui"), self)

        # Set the welcome_page as the initial view
        self.stackedWidget.setCurrentWidget(self.welcome_page)

        # Connect buttons to their respective functions
        self.continueButton.clicked.connect(self.gotoLogin)
        self.loginButton.clicked.connect(self.login)
        
        # Connect Enter key (returnPressed) to login
        self.usernameInput.returnPressed.connect(self.login)
        self.passwordInput.returnPressed.connect(self.login)

        # Set initial font sizes
        self.setInitialFontSizes()

    def setInitialFontSizes(self):
        # Set title font to 40px
        title_font = QFont("Times New Roman", 40, QFont.Bold)
        self.title.setFont(title_font)

        # Set description font to 16px
        description_font = QFont("Times New Roman", 16)
        self.description.setFont(description_font)

    def gotoLogin(self):
        # Switch to the login page
        self.stackedWidget.setCurrentWidget(self.login_page)

    def resizeEvent(self, event):
        # Calculate scaling factors based on both width and height
        base_title_font_size = 40
        base_description_font_size = 16
        scaling_factor = min(self.width() / 800, self.height() / 600)

        # Update title font
        new_title_font_size = max(int(base_title_font_size * scaling_factor), 20)  # Ensure minimum size
        title_font = QFont("Times New Roman", new_title_font_size, QFont.Bold)
        self.title.setFont(title_font)
        self.title.update()  # Force update

        # Update description font
        new_description_font_size = max(int(base_description_font_size * scaling_factor), 10)  # Ensure minimum size
        description_font = QFont("Times New Roman", new_description_font_size)
        self.description.setFont(description_font)
        self.description.update()  # Force update

        # Call the parent resize event
        super(MainApp, self).resizeEvent(event)

    def login(self):
        username = self.usernameInput.text().strip()
        password = self.passwordInput.text().strip()

        # Validate the input fields
        if not username or not password:
            self.error_message.setText("Please enter both username and password.")
            return

        # Connect to the SQLite database
        try:
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__),"database","users.db"))
            cursor = connection.cursor()

            # Check if the username exists
            query_username = "SELECT * FROM users WHERE username = ?"
            cursor.execute(query_username, (username,))
            user = cursor.fetchone()

            if not user:
                self.error_message.setText("Username does not exist.")
            elif user[4].strip() != password.strip():   
                self.error_message.setText("Incorrect password.")
            else:
                self.error_message.setText("")  # Clear the error message on successful login
                # Instead of opening a new window, switch to the first page in the current window
                self.switchToUploadPage(user)

            connection.close()

        except sqlite3.Error as e:
            self.error_message.setText(f"Database Error: {e}")

    def switchToUploadPage(self, user):
        # Check if the user is not a 'patient' (occupation is in the second column, index 1)
        if user[1].strip().lower() != "patient":  # Occupation is the second column (index 1)
            self.upload_window = UploadWindow(self)  # Pass the main window to the upload window
            self.upload_window.show()  # Show the upload window

            # Switch to the patients_page 
            self.upload_window.stackedWidget.setCurrentWidget(self.upload_window.patients_page)  
            
            # Hide the current main window instead of closing it
            self.hide()  
        else:
            self.error_message.setText("Access Denied: Patient users cannot access this page.")

class UploadWindow(QMainWindow):
    def __init__(self, parent=None):
        super(UploadWindow, self).__init__(parent)
        loadUi(os.path.join(os.path.dirname(__file__),"view", "uploadwindow.ui"), self)  # Load the correct UI
        
        # Initialize YOLOv7 detector
        weights_path = os.path.join(os.path.dirname(__file__),"model","best.pt")
        self.yolo_detector = YOLOv7Detector(weights_path)
        # Initialize the U-Net model
        model_path = os.path.join(os.path.dirname(__file__),"model","u_net_model_v2.h5")
        self.unet_model = UNetModel(model_path)
        # Ensure that the first page (page1_uploadHC) is set correctly in the stackedWidget
        self.stackedWidget.setCurrentWidget(self.patients_page)  # Set the initial page

        # Connect the menu toggle button
        self.menu_pushButton.clicked.connect(self.toggleMenu)

        # Connect table item click to the method
        self.patientTable.itemClicked.connect(self.on_table_item_clicked)
        
        # Connect menu buttons to their respective slots
        self.patients_pushButton.clicked.connect(self.show_patients_page)
        self.logout_pushButton.clicked.connect(self.show_welcome_page)

        # Load patient data into the table
        self.load_patient_data()

        # Set initial menu state
        self.menu_expanded = True
        self.menu_expanded_width = 150
        self.menu_collapsed_width = 10

        # Button connections for navigation
        self.mHC_pushButton.clicked.connect(self.switchToMeasureHCPage)
        self.next_pushButton_2.clicked.connect(self.switchToUploadFLPage)
        self.mFL_pushButton.clicked.connect(self.switchToMeasureFLPage)

        # Back buttons functionality
        self.back_pushButton.clicked.connect(self.switchToUploadHCPage)
        self.pushButton.clicked.connect(self.switchToUploadFLPage)
        
        # upload and reset buttons for page1_uploadHC
        self.resetHC_pushButton.clicked.connect(self.resetFileForHC)
        self.uploadHC_pushButton.clicked.connect(self.uploadFileForHC)
        
        # Connect upload and reset buttons for page3_uploadFL
        self.uploadFL_pushButton.clicked.connect(self.uploadFileForFL)
        self.resetFL_pushButton.clicked.connect(self.resetFileForFL)


        # Connect Save buttons on the HC and FL measurement result pages
        self.saveHC_pushButton.clicked.connect(self.saveHCMeasurement)
        self.saveFL_pushButton.clicked.connect(self.saveFLMeasurement)
        
        self.done_pushButton.clicked.connect(self.switchToLastPage)
        self.viewP_pushButton.clicked.connect(self.goToPatientInfo)
        
    def switchToLastPage(self):
        self.stackedWidget.setCurrentWidget(self.last_page) 
    
    def goToPatientInfo(self):
        self.patient_window = PatientWindow(self)  # Pass the main window to the upload window
        self.patient_window.show()  # Show the upload window

    def show_patients_page(self):
        """Switch to the Upload patients page."""
        self.stackedWidget.setCurrentWidget(self.patients_page)
        
    def show_welcome_page(self):
        self.main_window = MainApp()  # Instantiate the MainApp (login) window
        self.main_window.show()  # Show MainApp
        self.close()  # Close the UploadWindow
        
    def load_patient_data(self):
        """Load patient data from the database into the patientTable."""
        try:
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__),"database", "users.db"))
            cursor = connection.cursor()

            # Fetch all patients from the database
            query = "SELECT * FROM patients"  # Fetch all data from the patients table
            cursor.execute(query)
            patients = cursor.fetchall()

            # Clear the table before populating
            self.patientTable.clearContents()
            self.patientTable.setRowCount(0)  # Clear existing rows

            # Populate the table with patient data
            for patient in patients:
                row_position = self.patientTable.rowCount()
                self.patientTable.insertRow(row_position)
                # Assuming the patient data has columns: id, username, occupation, etc.
                self.patientTable.setItem(row_position, 0, QTableWidgetItem(str(patient[0])))  # ID
                self.patientTable.setItem(row_position, 1, QTableWidgetItem(patient[1]))  # Username
                self.patientTable.setItem(row_position, 2, QTableWidgetItem(patient[2]))  # Occupation
            

            connection.close()

        except sqlite3.Error as e:
            print(f"Database Error: {e}")

    def switchToMeasureHCPage(self):
        if not getattr(self, 'image_uploaded', False):
            QMessageBox.warning(self, "No Image", "Please upload an image first")
            return 
        """Switch to the HC measurement page."""
        self.stackedWidget.setCurrentWidget(self.page2_measureHC)

    def switchToUploadFLPage(self):
        """Switch to the Upload FL page."""
        self.stackedWidget.setCurrentWidget(self.page3_uploadFL)

    def switchToUploadHCPage(self):
        """Switch to the Upload HC page."""
        self.stackedWidget.setCurrentWidget(self.page1_uploadHC)
    def uploadFileForHC(self):
        """Simulate the upload and processing of HC images with model-based results."""
        file_name, _ = QFileDialog.getOpenFileName(self, "Upload Image for HC", "", "Images (*.png *.jpg *.jpeg *.bmp)")
        if file_name:
            # Display the selected file in a list
            self.listWidget.addItem(file_name)

            # Set the flag to indicate that an image has been uploaded
            self.image_uploaded = True

            # Process the image
            try:
                input_img = self.unet_model.preprocessing(file_name)
                output_img = self.unet_model.prediction(input_img)
                result_img, _, measurements = self.unet_model.final_preprocessing(output_img, input_img)

                # Update the UI
                self.displayUploadedHCImage(file_name)
                self.displayResultHCImage(result_img)
                self.mHC_label2.setText(f"HC: {measurements['HC']} cm")
                self.mBPD_label.setText(f"BPD: {measurements['BPD']} cm")
                self.mOFD_label.setText(f"OFD: {measurements['OFD']} cm")
            except Exception as e:
                QMessageBox.warning(self, "Error", f"Image processing failed: {e}")
        else:
            # Display warning if no image is selected
            QMessageBox.warning(self, "No Image", "Please upload an image before processing.")
            self.image_uploaded = False  # Reset flag if no image is uploaded



    def displayUploadedHCImage(self, file_name):
        """Display the uploaded HC image in the label."""
        pixmap = QPixmap(file_name)
        pixmap = pixmap.scaled(400, 400, Qt.IgnoreAspectRatio, Qt.SmoothTransformation)
        self.uploadedHCImage_label.setFixedSize(400, 400)
        self.uploadedHCImage_label.setAlignment(Qt.AlignCenter)
        self.uploadedHCImage_label.setPixmap(pixmap)

    def displayResultHCImage(self, result_img):
        """Display the result image (output from the model)."""
        height, width, channels = result_img.shape
        bytes_per_line = channels * width
        q_image = QImage(result_img.data, width, height, bytes_per_line, QImage.Format_RGB888)
        pixmap = QPixmap.fromImage(q_image)
        pixmap = pixmap.scaled(400, 400, Qt.IgnoreAspectRatio, Qt.SmoothTransformation)
        self.resultHCImage_label.setFixedSize(400, 400)
        self.resultHCImage_label.setAlignment(Qt.AlignCenter)
        self.resultHCImage_label.setPixmap(pixmap)

    def resetFileForHC(self):
        """Clear the list widget for HC uploads and reset images."""
        self.listWidget.clear()
        self.uploadedHCImage_label.clear()
        self.resultHCImage_label.clear()
    
    def load_model(self, weights_path="yolov7.pt"):
        print(f"Loading model from: {weights_path}")
        """
        Loads the YOLOv7 model using the YOLOv7Detector class.
        """
        #self.detector = YOLOv7Detector(weights_path)
        # Debug: print when the model is loaded
        if self.yolo_detector:
            print("YOLOv7 model loaded successfully.")
        else:
            print("Error: Failed to load YOLOv7 model.")
        
    def uploadFileForFL(self):
        """Handles FL image upload and processing with YOLOv7."""
        image_path, _ = QFileDialog.getOpenFileName(self, "Upload Image for FL", "", "Images (*.png *.jpg *.jpeg *.bmp)")
        
        if image_path:
            # Add the selected file path to the list
            self.listWidget_2.addItem(image_path)

            # Set the image_uploaded flag to True
            self.image_uploaded = True

            # Display the uploaded image
            pixmap = QPixmap(image_path)
            self.FL_inputIMG.setPixmap(pixmap.scaled(400, 400, aspectRatioMode=True))

            if not self.yolo_detector:
                print("Error: YOLOv7 detector not available.")
                return

            # Run YOLOv7 detection on the uploaded image
            output_img, measurements = self.yolo_detector.detect_image(image_path)

            if output_img is None:
                print("Error: YOLOv7 detection failed.")
                return

            # Display the processed image
            output_img_qt = self.convert_cv_to_qt(output_img)
            self.FL_outputIMG.setPixmap(output_img_qt.scaled(400, 400, aspectRatioMode=True))

            # Update the measurements display
            measurement_text = self.extract_measurement_text(measurements)
            self.mFL_label2.setText(f"Femur Length (FL): {measurement_text}")
            
        else:
            # If no image selected, reset the flag and show warning
            self.image_uploaded = False  # Reset the flag
            QMessageBox.warning(self, "No Image", "Please upload an image before processing.")

            


    def extract_measurement_text(self, measurements):
        """
        Converts the measurements list into a formatted string to be displayed in the UI.
        """
        if not measurements:
            return "No detections found."
 
        for i, data in enumerate(measurements):
            femur_length_cm = data['femur_length_cm']
            measurement_text = f"{femur_length_cm:.2f} cm\n"

        
        return measurement_text


        
    def switchToMeasureFLPage(self):
        """Strict check to ensure an image has been uploaded before switching to the FL measurement page."""
        if not getattr(self, 'image_uploaded', False):  # Check if the image_uploaded flag is False
            QMessageBox.warning(self, "No Image", "Please upload an image first before proceeding.")
            return  # Prevent the switch to the FL page

        # If the image has been uploaded, proceed to the FL measurement page
        self.stackedWidget.setCurrentWidget(self.page4_measureFL)




    def convert_cv_to_qt(self, cv_img):
        """
        Converts an OpenCV image to QPixmap for displaying in a QLabel.
        """
        rgb_image = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        qt_image = QImage(rgb_image.data, w, h, bytes_per_line, QImage.Format_RGB888)
        return QPixmap.fromImage(qt_image)
     
            
    def resetFileForFL(self):
        # Clear the list widget (listWidget_2) for FL
        self.listWidget_2.clear()

    
    def saveHCMeasurement(self):
        """Save HC measurement to the database from the HC measurement results page."""
        try:
            # Extract HC measurement
            hc_measurement = self.mHC_label2.text().strip()  # Example: "HC: 12.44 cm"

            if hc_measurement.startswith("HC:"):
                hc_value = float(hc_measurement.replace("HC:", "").replace("cm", "").strip())
            else:
                QMessageBox.warning(self, "Error", "Invalid HC measurement format.")
                return

            # Ensure a patient is selected
            patient_id = getattr(self, "selected_patient_id", None)
            if not patient_id:
                QMessageBox.warning(self, "Error", "No patient selected. Please select a patient.")
                return

            # Set a default value for `fl` (femur length)
            fl_value = 0.0   

            # Save to the database
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database","users.db"))
            cursor = connection.cursor()
            cursor.execute(
                """
                INSERT INTO measurements (patient_id, hc, fl, timestamp, image_path)
                VALUES (?, ?, ?, CURRENT_TIMESTAMP, NULL)
                """,
                (patient_id, hc_value, fl_value)
            )
            connection.commit()
            connection.close()

            # Provide success feedback
            QMessageBox.information(self, "Success", f"HC measurement ({hc_value} cm) saved successfully.")

        except ValueError:
            QMessageBox.warning(self, "Error", "Invalid HC measurement format.")
        except sqlite3.Error as e:
            QMessageBox.warning(self, "Error", f"Database error: {e}")


    def saveFLMeasurement(self):
        """Save FL measurement to the database from the FL measurement results page."""
        try:
            # Get the FL measurement result from the QLabel
            fl_measurement = self.mFL_label2.text().strip()

            # Debug: Print the label text
            print(f"Label Text: {fl_measurement}")

            # Check if label text is empty
            if not fl_measurement:
                QMessageBox.warning(self, "Error", "FL measurement result is empty. Please process the image first.")
                return

            # Extract the numeric FL value
            try:
                fl_value = float(fl_measurement.split(":")[1].strip().split()[0])  # Correct parsing logic
            except (ValueError, IndexError):
                QMessageBox.warning(self, "Error", "Invalid FL measurement format. Please check the result.")
                return

            # Get selected patient ID
            patient_id = getattr(self, "selected_patient_id", None)

            # Validate patient selection
            if not patient_id:
                QMessageBox.warning(self, "Error", "No patient selected. Please select a patient.")
                return

            # Connect to the database and save the measurement
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__),"database", "users.db"))
            cursor = connection.cursor()

            # Insert data into the measurements table
            cursor.execute(
                """
                INSERT INTO measurements (patient_id, hc, fl, timestamp, image_path)
                VALUES (?, ?, ?, CURRENT_TIMESTAMP, NULL)
                """,
                (patient_id, 0, fl_value)  
            )
            connection.commit()
            connection.close()

            # Provide success feedback
            QMessageBox.information(self, "Success", f"FL measurement ({fl_value} cm) saved successfully.")

        except sqlite3.Error as e:
            # Handle database errors
            QMessageBox.warning(self, "Error", f"Database error: {e}")



    def toggleMenu(self):
        """Animate the side menu toggle."""
        animation = QPropertyAnimation(self.menu_widget, b"maximumWidth")
        animation.setDuration(300)  # Duration in milliseconds
        if self.menu_expanded:
            animation.setStartValue(self.menu_expanded_width)
            animation.setEndValue(self.menu_collapsed_width)
        else:
            animation.setStartValue(self.menu_collapsed_width)
            animation.setEndValue(self.menu_expanded_width)
        
        animation.start()
        self.menu_expanded = not self.menu_expanded

    def on_table_item_clicked(self, item):
        """Handle the table item click event."""
        # Get the selected patient ID from the clicked item (assuming it's in the first column)
        self.selected_patient_id = int(self.patientTable.item(item.row(), 0).text())   
        # Switch to the Upload HC page
        self.stackedWidget.setCurrentWidget(self.page1_uploadHC)  


class PatientWindow(QMainWindow):
    def __init__(self, parent=None):
        super(PatientWindow, self).__init__(parent)
        
        # Load the UI file
        loadUi(os.path.join(os.path.dirname(__file__), "view","patientwindow.ui"), self)
        
        # Set initial window size (slightly smaller than the default size)
        self.setFixedSize(800, 600)   
        
        # Add a scroll area to handle overflowing content
        scroll_area = QScrollArea(self)
        scroll_area.setWidgetResizable(True)  # Makes the content inside scrollable
        
        # Add the main widget as the content of the scroll area
        scroll_area.setWidget(self.main_widget)  
        
        # Set the scroll area as the central widget
        self.setCentralWidget(scroll_area)

    
    
def main():
    app = QApplication(sys.argv)
    main_app = MainApp()
    main_app.show()
    try:
        sys.exit(app.exec_())
    except SystemExit:
        print("Application closed.")

if __name__ == "__main__":
    main()
