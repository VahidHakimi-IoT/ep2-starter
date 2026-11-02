# Project Report — ESP32-S3 Gesture Recognition

**Member:** Vahid Hakimi (individual project)

## What it does

This project implements a gesture-recognition system using an ESP32-S3 and an MPU6050 accelerometer. It classifies device movement into three classes: idle, shake, and wave. The trained machine-learning model runs locally on the ESP32-S3 and reports the predicted class and confidence through the Serial Monitor. When confidence is below 60%, the output is reported as uncertain.

## How it works

The MPU6050 measures acceleration along the X, Y, and Z axes. The ESP32-S3 collects the sensor values and passes them to the deployed Edge Impulse classifier. The model predicts idle, shake, or wave, and the program displays the predicted class and confidence over serial. The program also measures and prints the inference time.

**Pipeline:** MPU6050 → ESP32-S3 → trained classifier → predicted gesture, confidence, and inference time.

## Data

The Edge Impulse dataset contains nine recordings: three idle, three shake, and three wave. Each recording is approximately nine seconds long and contains X, Y, and Z acceleration data sampled at 50 Hz. The recordings were made on September 22, 2026. **Recorder:** Vahid Hakimi, if confirmed. The dataset is small and may not represent different people, movement speeds, or recording conditions. The Edge Impulse training/testing split should be checked before reporting model test-set accuracy.

## Results — honestly

In a separate practical test on the physical device, the classifier correctly identified 5/5 idle attempts, 3/5 shake attempts, and 4/5 wave attempts. This gives 12 correct predictions out of 15 attempts, or **80% observed accuracy** on this small test. Shake was the weakest class in this test. Shake and wave both involve movement, so their acceleration patterns may sometimes be similar. More tests and additional training recordings are needed to determine whether this is a consistent weakness.

The measured inference time was approximately **5 ms**, measured around the classifier call using `millis()`. This is an approximate measurement with millisecond timer resolution. Insert the Edge Impulse confusion-matrix screenshot and report its test-set accuracy here when available.

## The two sentences

**Platform:** We use the ESP32-S3 with the Arduino framework and PlatformIO because it can collect MPU6050 accelerometer data and run the trained gesture-classification model locally on the device.

**Threat model:** Confirm the asset, threat, and response against the actual project requirements before submitting this sentence.

## What was hard, and what you'd do next

Integrating the MPU6050, deploying the Edge Impulse model, and verifying serial output on the ESP32-S3 required hardware and software troubleshooting. The practical tests showed that shake was harder to recognise reliably than idle or wave. With another week, I would collect more balanced recordings under different movement speeds and conditions, then evaluate the model on separate test data. I would also test more attempts per class and compare the results with the confusion matrix.

## Who did what

**Vahid Hakimi** — connected and tested the MPU6050, integrated and deployed the gesture-classification model, implemented class prediction and inference-time reporting, and tested the device.

## AI use

ChatGPT was used to help understand the assignment requirements, troubleshoot PlatformIO and serial-monitor issues, review the gesture-recognition implementation, and structure the report. The code was compiled and tested on the physical ESP32-S3, and the reported practical test results came from device testing.