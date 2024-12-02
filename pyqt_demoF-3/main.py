import sys
import os
import torch
import cv2
import numpy as np
import sqlite3
from view import resources_rc
import math
sys.path.append(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(os.path.join(os.path.dirname(__file__), "model", "yolov7"))
from model.YOLOv7Detector import YOLOv7Detector
from model.UNnetModel import UNetModel

from PyQt5 import QtCore, QtGui
from PyQt5.uic import loadUi
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QLabel, QDialog, QFileDialog, QPushButton, QVBoxLayout, QWidget, QTableWidget, QTableWidgetItem
from PyQt5.QtGui import QFont, QPixmap, QImage, QPainter
from PyQt5.QtCore import QPropertyAnimation, Qt, QIODevice, QTextStream, QFile, QTextStream
from PyQt5.QtWidgets import QScrollArea
from PyQt5.QtPrintSupport import QPrinter, QPrintDialog
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtCore import QByteArray
from io import BytesIO


class MainApp(QMainWindow):
    def __init__(self):
        super(MainApp, self).__init__()
        loadUi(os.path.join(os.path.dirname(__file__), "view", "mainwindow.ui"), self)

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
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database", "users.db"))
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
        # Check if the user is a 'sonographer'
        if user[1].strip().lower() == "sonographer":  # Checking if the occupation is sonographer
            doctor_id = user[0]  # Get the doctor's ID (user[0] is the doctor ID from the database)
            
            # Pass only the doctor_id to UploadWindow, not the full user data
            self.upload_window = UploadWindow(doctor_id)  # We pass doctor_id here
            self.upload_window.show()  # Show the upload window
            self.hide()  # Hide the main window (doesn't terminate the app, just hides it)
        else:
            # If not a sonographer, deny access
            self.error_message.setText("Access Denied: Only Sonographers can access this page.")



class UploadWindow(QMainWindow):
    def __init__(self, doctor_id, parent=None):
        super(UploadWindow, self).__init__(parent)
        loadUi(os.path.join(os.path.dirname(__file__),"view", "uploadwindow.ui"), self)  # Load the correct UI
        
        # Initialize YOLOv7 detector
        weights_path = os.path.join(os.path.dirname(__file__),"model","best.pt")
        self.yolo_detector = YOLOv7Detector(weights_path)
        # Initialize the U-Net model
        model_path = os.path.join(os.path.dirname(__file__),"model","u_net_model_v2.h5")
        self.unet_model = UNetModel(model_path)
        
        self.doctor_id = doctor_id  # Store the doctor's ID
        
        # Ensure that the first page (patients_page) is set correctly in the stackedWidget
        self.stackedWidget.setCurrentWidget(self.patients_page)
        
        # Set initial menu state
        self.menu_expanded = True
        self.menu_expanded_width = 150
        self.menu_collapsed_width = 10
        # Connect the menu toggle button
        self.menu_pushButton.clicked.connect(self.toggleMenu)
        # Connect menu buttons to their respective slots
        self.patients_pushButton.clicked.connect(self.show_patients_page)
        self.logout_pushButton.clicked.connect(self.show_welcome_page)
        
        # Load patient data into the table
        self.load_patient_data()
        # Connect table item click to the method
        self.patientTable.itemClicked.connect(self.on_table_item_clicked)

        # upload and reset buttons for page1_uploadHC
        self.uploadHC_pushButton.clicked.connect(self.uploadFileForHC)
        self.resetHC_pushButton.clicked.connect(self.resetFileForHC)
        # page1_uploadHC measure button
        self.mHC_pushButton.clicked.connect(self.switchToMeasureHCPage)
        # page2_measureHC back button, go to page1_uploadHC
        self.back_pushButton.clicked.connect(self.switchToUploadHCPage)
        # page2_measureHC next button, go to page3_uploadFL
        self.next_pushButton_2.clicked.connect(self.switchToUploadFLPage)
        # page2_measureHC save button
        self.saveHC_pushButton.clicked.connect(self.saveHCMeasurement)
        
    
        # upload and reset buttons for page3_uploadFL
        self.uploadFL_pushButton.clicked.connect(self.uploadFileForFL)
        self.resetFL_pushButton.clicked.connect(self.resetFileForFL)
        # page3_uploadFL meaure button
        self.mFL_pushButton.clicked.connect(self.switchToMeasureFLPage)
        # page4_measureFL back button, go to page3_uploadFL
        self.pushButton.clicked.connect(self.switchToUploadFLPage)
        # page4_measureFL done button, go to last_page
        self.done_pushButton.clicked.connect(self.switchToLastPage)
        # page4_measureFL save button
        self.saveFL_pushButton.clicked.connect(self.saveFLMeasurement)
        
        # last_page view button, go to patientwindow.ui
        self.pushButton_2.clicked.connect(self.goToPatientInfo)
        
    # Menu Functions buttons    
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
        
    def show_patients_page(self):
        """Switch to the patients page."""
        self.stackedWidget.setCurrentWidget(self.patients_page)
        
    def show_welcome_page(self):
        self.main_window = MainApp()  # Instantiate the MainApp (login) window
        self.main_window.show()  # Show MainApp
        self.close()  # Close the UploadWindow
        
        
    # load info from db onto the patientTable (1st page) 
    def load_patient_data(self):
        """Load patient data from the database into the patientTable."""
        try:
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database", "users.db"))
            cursor = connection.cursor()

            # Fetch patients associated with the logged-in doctor
            query = "SELECT id, name, dob FROM patients_list WHERE doctor_id = ?"
            cursor.execute(query, (self.doctor_id,))
            patients = cursor.fetchall()

            # Clear the table before populating
            self.patientTable.clearContents()
            self.patientTable.setRowCount(0)  # Clear existing rows

            # Populate the table with patient data
            for patient in patients:
                row_position = self.patientTable.rowCount()
                self.patientTable.insertRow(row_position)

                # Assuming the columns match the order in the SELECT query
                self.patientTable.setItem(row_position, 0, QTableWidgetItem(str(patient[0])))  # ID
                self.patientTable.setItem(row_position, 1, QTableWidgetItem(patient[1]))  # Name
                self.patientTable.setItem(row_position, 2, QTableWidgetItem(patient[2]))       # DOB (Index 3)

            connection.close()

        except sqlite3.Error as e:
            QMessageBox.warning(self, "Error", f"Database error: {e}")
               
    def on_table_item_clicked(self, item):
        """Handle the table item click event."""
        # Get the selected patient ID from the clicked item (assuming it's in the first column)
        self.selected_patient_id = int(self.patientTable.item(item.row(), 0).text())   
        # Switch to the Upload HC page
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

                # Save the images to the database
                patient_id = getattr(self, "selected_patient_id", None)
                if patient_id:
                    self.saveImageAsBlob(file_name, patient_id, "hc_image")  # Save uploaded HC image
                    self.saveImageAsBlob(result_img, patient_id, "hc_seg_img")  # Save processed HC image

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
    
    def switchToMeasureHCPage(self):
        if not getattr(self, 'image_uploaded', False):
            QMessageBox.warning(self, "No Image", "Please upload an image first")
            return 
        """Switch to the HC measurement page."""
        self.stackedWidget.setCurrentWidget(self.page2_measureHC)
        
    # page2_meaureHC back button         
    def switchToUploadHCPage(self):
        """Switch to the Upload HC page."""
        self.stackedWidget.setCurrentWidget(self.page1_uploadHC) 
        
    # page2_measureHC next button + page4_measureFL back button
    def switchToUploadFLPage(self):
        """Switch to the Upload FL page."""
        self.stackedWidget.setCurrentWidget(self.page3_uploadFL)  
    
    
    def saveHCMeasurement(self):
        """Save HC, BPD, and OFD measurements to the database."""
        try:
            # Extract HC, BPD, and OFD measurements
            hc_measurement = self.mHC_label2.text().strip()   
            bpd_measurement = self.mBPD_label.text().strip()   
            ofd_measurement = self.mOFD_label.text().strip()  

            # Validate and convert measurements
            if hc_measurement.startswith("HC:"):
                hc_value = float(hc_measurement.replace("HC:", "").replace("cm", "").strip())
            else:
                QMessageBox.warning(self, "Error", "Invalid HC measurement format.")
                return

            if bpd_measurement.startswith("BPD:"):
                bpd_value = float(bpd_measurement.replace("BPD:", "").replace("cm", "").strip())
            else:
                QMessageBox.warning(self, "Error", "Invalid BPD measurement format.")
                return

            if ofd_measurement.startswith("OFD:"):
                ofd_value = float(ofd_measurement.replace("OFD:", "").replace("cm", "").strip())
            else:
                QMessageBox.warning(self, "Error", "Invalid OFD measurement format.")
                return

            # Ensure a patient is selected
            patient_id = getattr(self, "selected_patient_id", None)
            if not patient_id:
                QMessageBox.warning(self, "Error", "No patient selected. Please select a patient.")
                return

            # Save to the database (check if a record for this patient already exists)
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database", "users.db"))
            cursor = connection.cursor()

            # Check if a row exists for the patient_id
            cursor.execute("SELECT id FROM measurements WHERE patient_id = ?", (patient_id,))
            existing_record = cursor.fetchone()

            if existing_record:
                # Update existing record
                cursor.execute(
                    """
                    UPDATE measurements
                    SET hc_measurement = ?, bpd_measurement = ?, ofd_measurement = ?, study_date = CURRENT_TIMESTAMP
                    WHERE patient_id = ?
                    """,
                    (hc_value, bpd_value, ofd_value, patient_id)
                )
            else:
                # Insert new record if no existing record
                cursor.execute(
                    """
                    INSERT INTO measurements (patient_id, hc_measurement, bpd_measurement, ofd_measurement, study_date)
                    VALUES (?, ?, ?, ?, CURRENT_TIMESTAMP)
                    """,
                    (patient_id, hc_value, bpd_value, ofd_value)
                )

            connection.commit()
            connection.close()

            # Provide success feedback
            QMessageBox.information(
                self,
                "Success",
                f"Measurements saved successfully:\nHC: {hc_value} cm\nBPD: {bpd_value} cm\nOFD: {ofd_value} cm"
            )

        except ValueError:
            QMessageBox.warning(self, "Error", "Invalid measurement format.")
        except sqlite3.Error as e:
            QMessageBox.warning(self, "Error", f"Database error: {e}")
    
    
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

            # Set the img_uploaded flag to True
            self.img_uploaded = True

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

            # Save the images to the database
            patient_id = getattr(self, "selected_patient_id", None)
            if patient_id:
                self.saveImageAsBlob(image_path, patient_id, "fl_image")  # Save uploaded FL image
                self.saveImageAsBlob(output_img, patient_id, "fl_seg_img")  # Save processed FL image
                
        else:
            # If no image selected, reset the flag and show warning
            self.img_uploaded = False  # Reset the flag
            QMessageBox.warning(self, "No Image", "Please upload an image before processing.")

    def convert_cv_to_qt(self, cv_img):
        """
        Converts an OpenCV image to QPixmap for displaying in a QLabel.
        """
        rgb_image = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        qt_image = QImage(rgb_image.data, w, h, bytes_per_line, QImage.Format_RGB888)
        return QPixmap.fromImage(qt_image)
    
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
            
    def resetFileForFL(self):
        # Clear the list widget (listWidget_2) for FL
        self.listWidget_2.clear()
        
    def switchToMeasureFLPage(self):
        """Strict check to ensure an image has been uploaded before switching to the FL measurement page."""
        if not getattr(self, 'img_uploaded', False):  # Check if the img_uploaded flag is False
            QMessageBox.warning(self, "No Image", "Please upload an image first before proceeding.")
            return  # Prevent the switch to the FL page
        
        # If the image has been uploaded, proceed to the FL measurement page
        self.stackedWidget.setCurrentWidget(self.page4_measureFL)
    
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

            # Set default values for other measurements
            hc_value = 0.0
            bpd_value = 0.0
            ofd_value = 0.0

            # Connect to the database and save the measurement
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database", "users.db"))
            cursor = connection.cursor()

            # Check if a row exists for the patient_id
            cursor.execute("SELECT id FROM measurements WHERE patient_id = ?", (patient_id,))
            existing_record = cursor.fetchone()

            if existing_record:
                # Update existing record
                cursor.execute(
                    """
                    UPDATE measurements
                    SET fl_measurement = ?, study_date = CURRENT_TIMESTAMP
                    WHERE patient_id = ?
                    """,
                    (fl_value, patient_id)
                )
            else:
                # Insert new record if no existing record
                cursor.execute(
                    """
                    INSERT INTO measurements (patient_id, hc_measurement, bpd_measurement, ofd_measurement, fl_measurement, study_date)
                    VALUES (?, ?, ?, ?, ?, CURRENT_TIMESTAMP)
                    """,
                    (patient_id, hc_value, bpd_value, ofd_value, fl_value)
                )

            connection.commit()
            connection.close()

            # Provide success feedback
            QMessageBox.information(self, "Success", f"FL measurement ({fl_value} cm) saved successfully.")

        except sqlite3.Error as e:
            # Handle database errors
            QMessageBox.warning(self, "Error", f"Database error: {e}")
    
    def switchToLastPage(self):
        self.stackedWidget.setCurrentWidget(self.last_page) 
    
    def goToPatientInfo(self):
        # Pass the selected_patient_id to the PatientWindow
        self.patient_window = PatientWindow(self.selected_patient_id, self)  # Pass patient_id to PatientWindow
        self.patient_window.show()  # Show the patient window

        
    
    def saveImageAsBlob(self, image_data, patient_id, column_name):
        """Helper function to save an image as BLOB to the database."""
        try:
            if isinstance(image_data, str):  # Check if the image is a file path
                # Open the image file and convert it to binary (BLOB)
                with open(image_data, "rb") as image_file:
                    image_data = image_file.read()  # Read the image as binary data
            elif isinstance(image_data, np.ndarray):  # If it's an image array (ndarray)
                _, encoded_image = cv2.imencode('.jpg', image_data)  # Convert ndarray to byte data
                image_data = encoded_image.tobytes()  # Convert the image to bytes
            
            # Connect to the database
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database", "users.db"))
            cursor = connection.cursor()

            # Update the corresponding image column for the patient
            cursor.execute(f"""
                UPDATE measurements
                SET {column_name} = ?
                WHERE patient_id = ?
            """, (image_data, patient_id))

            connection.commit()
            connection.close()

        except sqlite3.Error as e:
            QMessageBox.warning(self, "Error", f"Database error: {e}")
  



class PatientWindow(QMainWindow):
    def __init__(self, patient_id, parent=None):
        super(PatientWindow, self).__init__(parent)

        # Load the UI
        loadUi(os.path.join(os.path.dirname(__file__), "view", "patientwindow.ui"), self)

        self.setFixedSize(800, 600)

        scroll_area = QScrollArea(self)
        scroll_area.setWidgetResizable(True)
        scroll_area.setWidget(self.centralwidget)
        self.setCentralWidget(scroll_area)

        # Fetch and display patient information using the patient_id
        self.displayPatientInfo(patient_id)
        
        # download button
        self.download_pushButton.clicked.connect(self.on_download_button_clicked)

    def displayPatientInfo(self, patient_id):
        """Fetch the patient's data and display it in the UI."""
        try:
            # Connect to the database
            connection = sqlite3.connect(os.path.join(os.path.dirname(__file__), "database", "users.db"))
            cursor = connection.cursor()

            # Fetch patient details from the patients_list table
            cursor.execute("SELECT name, id, dob, doctor_id FROM patients_list WHERE id = ?", (patient_id,))
            patient = cursor.fetchone()

            if patient:
                name, id, dob, doctor_id = patient
                self.name_label.setText(name)  # Set the patient's name
                self.name_label.setFont(QFont("Times New Roman", 18, QFont.Bold))   
                self.ID_label.setText(f"PATIENT ID: {str(id)}")     # Set the patient's ID
                self.DOB_label.setText(f"DOB: {dob}")  # Set the patient's DOB

                # Fetch the doctor (performed by) details from the users table
                cursor.execute("SELECT name FROM users WHERE id = ?", (doctor_id,))
                doctor = cursor.fetchone()
                if doctor:
                    self.by_label.setText(f"PERFORMED BY: {doctor[0]}")  # Set the doctor's name
                else:
                    self.by_label.setText("PERFORMED BY: Unknown")

                # Fetch measurements and images from the measurements table
                cursor.execute("""
                    SELECT study_date, hc_measurement, bpd_measurement, ofd_measurement, fl_measurement, 
                           hc_image, hc_seg_img, fl_image, fl_seg_img
                    FROM measurements 
                    WHERE patient_id = ?
                    ORDER BY study_date DESC LIMIT 1
                """, (patient_id,))
                measurements = cursor.fetchone()

                if measurements:
                    study_date, hc, bpd, ofd, fl, hc_image, hc_seg_img, fl_image, fl_seg_img = measurements
                    self.date_label.setText(f"STUDY DATE: {study_date}")  # Set study date
                    self.hc_label.setText(f"{hc} cm")  # Set HC measurement
                    self.bpd_label.setText(f"{bpd} cm")  # Set BPD measurement
                    self.ofd_label.setText(f"{ofd} cm")  # Set OFD measurement
                    self.fl_label.setText(f"{fl} cm")  # Set FL measurement

                    # Display the images in the respective labels
                    if hc_image:
                        self.displayImageFromBlob(hc_image, self.US1_label)
                    if hc_seg_img:
                        self.displayImageFromBlob(hc_seg_img, self.US2_label)
                    if fl_image:
                        self.displayImageFromBlob(fl_image, self.US3_label)
                    if fl_seg_img:
                        self.displayImageFromBlob(fl_seg_img, self.US4_label)
                else:
                    # If no data is found, display no data available for measurements and images
                    self.hc_label.setText("HC: No data available")
                    self.bpd_label.setText("BPD: No data available")
                    self.ofd_label.setText("OFD: No data available")
                    self.fl_label.setText("FL: No data available")
                    self.US1_label.clear()
                    self.US2_label.clear()
                    self.US3_label.clear()
                    self.US4_label.clear()

            else:
                QMessageBox.warning(self, "Error", "No patient found with the provided ID.")

            connection.close()

        except sqlite3.Error as e:
            QMessageBox.warning(self, "Database Error", f"An error occurred: {e}")

    def displayImageFromBlob(self, image_data, label):
        """Converts image BLOB to QPixmap and displays it in the given label."""
        

        # Convert BLOB to QImage
        image = QImage.fromData(QByteArray(image_data))
        if image.isNull():
            label.setText("No image available")
        else:
            # Convert QImage to QPixmap and display in the label
            pixmap = QPixmap.fromImage(image)
            label.setPixmap(pixmap.scaled(400, 400, aspectRatioMode=True))
            
    def on_download_button_clicked(self):
        """Handles the download button click event."""
       
        self.download_pushButton.setVisible(False)

        # Open the save file dialog to choose where to save the PDF
        file_name, _ = QFileDialog.getSaveFileName(self, "Save Patient Info", "", "PDF Files (*.pdf)")

        if file_name:
            # Create a QPrinter object to render the window content
            printer = QPrinter(QPrinter.HighResolution)
            printer.setOutputFormat(QPrinter.PdfFormat)
            printer.setOutputFileName(file_name)

            # Create a QPainter object to handle the painting process
            painter = QPainter()

            if painter.begin(printer):
                # Get the size of the full content (including scrollable part)
                content_rect = self.centralwidget.rect()  # Full content size of the central widget

                # Create an off-screen QPixmap to render the full content
                full_pixmap = QPixmap(content_rect.size())  # Full content area
                full_pixmap.fill(Qt.white)   

                # Create a painter to render to the pixmap
                pixmap_painter = QPainter(full_pixmap)
                self.centralwidget.render(pixmap_painter)  # Render the full content to the pixmap
                pixmap_painter.end()

                # Get the size of the printer's page
                page_rect = printer.pageRect()
                page_width = page_rect.width()
                page_height = page_rect.height()

                # Calculate scaling factor based on the page size and content size
                scale_factor_width = page_width / full_pixmap.width()
                scale_factor_height = page_height / full_pixmap.height()
                scale_factor = min(scale_factor_width, scale_factor_height)  # Fit content to the page

                # Apply the scaling factor to the painter
                painter.scale(scale_factor, scale_factor)

                # Draw the pixmap onto the PDF page
                painter.drawPixmap(0, 0, full_pixmap)

                # End the painting process
                painter.end()

                # Inform the user that the file has been saved
                QMessageBox.information(self, "PDF Saved", f"Patient info saved as PDF: {file_name}")
            else:
                QMessageBox.warning(self, "Failed to generate PDF", "The PDF could not be generated.")
        else:
            QMessageBox.warning(self, "No file selected", "Please select a location to save the PDF.")

       
        self.download_pushButton.setVisible(True)

        
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
