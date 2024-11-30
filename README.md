# FetalVision: AI-Enabled Real-Time Fetal Biometry Detection in 2D Ultrasound

FetalVision is a project aimed at leveraging deep learning models for real-time fetal biometry estimation using 2D ultrasound images. This repository contains implementations of two deep learning models: U-Net and Yolov7, trained on a custom dataset for this specific task.

## Introduction

Ultrasound imaging is a widely used diagnostic tool in obstetrics for monitoring fetal development and detecting abnormalities. Fetal biometry involves measurements of fetal anatomy such as head circumference, femur length, and abdominal circumference, which are crucial for assessing fetal growth and well-being. Traditional manual measurements can be time-consuming and subjective, motivating the need for automated and accurate methods.

## Features

- Real-time fetal biometry estimation
- U-Net and Yolov7 models for semantic segmentation
- Custom dataset for training and evaluation


## Dataset

Fetal Head Circumference Dataset (Kaggle)
The dataset we utilized for fetal head circumference, obtained from Kaggle[16], was divided into
three main sets: training, testing, and validation. Each set consisted of three directories: images,
annotations, and labels. The breakdown is as follows:
  - Training set: 699 files
  - Testing set: 101 files
  - Validation set: 199 files

Overall, we worked with 999 ultrasound images in our project. Additionally, we incorporated the
YOLO obb.yaml file for configuring and training specific models to improve accuracy in detection
and classification tasks.
Link to the dataset on Kaggle : https://www.kaggle.com/datasets/theunkovvn/fetal-head-circumference

Femur Length Dataset (Roboflow)
The dataset we utilized, obtained from Roboflow[17], was divided into three main sets: training,
validation, and testing. The breakdown is as follows:

 - Training set: 2,087 images
 - Validation set: 201 images
 - Testing set: 101 images

Each set was organized into directories, with images separated from any annotations or labels to
facilitate model training and evaluation.
In total, we worked with 2,389 images for our project. Additionally, we incorporated the YOLO
obb.yaml file for configuring and training specific models, which allowed for more efficient and
accurate detection and classification tasks.
Link to the dataset on Roboflow : https://universe.roboflow.com/eemur/eemur/dataset/10


## Requirements

- Python 3
- TensorFlow
- Keras
- NumPy
- OpenCV
- Matplotlib
- scikit-learn
- PyQt5

# U-Net Model Setup and Execution Guide

This repository contains the U-Net model code. Follow the steps below to set up your environment and run the model.

## 1. Download the Model Weights

First, you need to download the pre-trained model weights. You can get them from the provided link below:

- [Download U-Net Weights](<https://drive.google.com/file/d/1mAGhIYvXVUE59TMctE9AR0_AisIZ3M5l/view?usp=share_link>)

After downloading the weights (`unet_weights.h5`), **move** or **copy** the weights file into the `model` folder in the repository.


## 2. Set Up the Virtual Environment

Next, you'll need to set up a Python virtual environment to install all the necessary dependencies.


### 2.1. Create a Virtual Environment

Run the following command to create a virtual environment in your project directory:
```bash
python3 -m venv venv

2.3. Install Dependencies
pip install -r rose_requirements.txt

### 3 Run the Model
```bash
python3 main.py
