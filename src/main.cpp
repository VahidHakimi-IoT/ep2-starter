
/*
 * Session 4 — Run your trained Edge Impulse model on the board.
 * Step 6 — Measure inference time using millis().
 */

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include <Wave_inferencing.h>

Adafruit_MPU6050 mpu;

float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];
int i = 0;

void act_on(ei_impulse_result_t &result) {
  int best = 0;
  float best_val = 0.0f;

  for (int k = 0; k < EI_CLASSIFIER_LABEL_COUNT; k++) {
    if (result.classification[k].value > best_val) {
      best_val = result.classification[k].value;
      best = k;
    }
  }

  if (best_val > 0.60f) {
    Serial.printf(
      "Gesture: %s (%.0f%% confidence)\n",
      result.classification[best].label,
      best_val * 100.0f
    );
  } else {
    Serial.printf(
      "Gesture: uncertain (%.0f%% confidence)\n",
      best_val * 100.0f
    );
  }
}

void setup() {
  Serial.begin(115200);
  delay(300);

  Wire.begin(8, 9);

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (true) {
      delay(1000);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  Serial.println("Edge Impulse gesture recognition");
  Serial.println("Inference timing enabled.");
}

void loop() {
  sensors_event_t a, g, t;
  mpu.getEvent(&a, &g, &t);

  buffer[i++] = a.acceleration.x;
  buffer[i++] = a.acceleration.y;
  buffer[i++] = a.acceleration.z;

  if (i >= EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
    signal_t signal;

    numpy::signal_from_buffer(
      buffer,
      EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE,
      &signal
    );

    ei_impulse_result_t result;

    // STEP 6: Measure the classifier execution time.
    uint32_t startTime = millis();

    EI_IMPULSE_ERROR inferenceError =
      run_classifier(&signal, &result, false);

    uint32_t inferenceTime = millis() - startTime;

    if (inferenceError != EI_IMPULSE_OK) {
      Serial.printf(
        "Classifier failed with error: %d\n",
        inferenceError
      );
    } else {
      Serial.printf(
        "Inference time: %lu ms\n",
        (unsigned long)inferenceTime
      );

      act_on(result);
    }

    // Start collecting the next sensor window.
    i = 0;
  }

  delay(20);  // Approximately 50 Hz sensor sampling
}
