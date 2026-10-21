# Data Plan — ESP32-S3 Gesture Recognition

**Team:** Vahid Hakimi (individual project)

## Sensor

The device uses the MPU6050 accelerometer connected to the ESP32-S3 through I²C. The sensor uses SDA on GPIO 8 and SCL on GPIO 9. The model uses the measured acceleration values as input for gesture recognition.

## Classes

The device distinguishes three classes:

- **Idle:** no intentional movement.
- **Shake:** shaking the device.
- **Wave:** waving the device.

## Collection

## Collection

I recorded the accelerometer data using the MPU6050 connected to the ESP32-S3. The dataset contains 9 recordings: 3 idle, 3 shake, and 3 wave. Each recording is approximately 9 seconds long and contains X, Y, and Z acceleration data sampled at 50 Hz. I recorded the three classes on September 22, 2026.

The recordings were collected by Vahid Hakimi. The dataset is small, so additional recordings under different movement speeds and conditions would help improve robustness. The training and testing split should be verified in Edge Impulse Studio before reporting the evaluation results.
## Risk

The most likely classes to confuse are **shake and wave**, because both involve movement and may produce similar acceleration patterns. Idle may also be confused with a gesture if the device moves slightly while being held.