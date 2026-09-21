// Tilt axis/threshold: Z > 4.0 m/s^2 enables the LED.
// Readings: UP Z = +8.34 to +8.47; SIDEWAYS Z = -1.66 to -1.83; DOWN Z = -2.66 to -2.99.
// Testing surprise: The potentiometer values kept changing even when the LED was off.

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>

#define POT_PIN 4
#define LED_PIN 40
#define TILT_THRESHOLD 4.0

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  delay(300);

  pinMode(LED_PIN, OUTPUT);

  // MPU-6050: SDA = GPIO8, SCL = GPIO9
  Wire.begin(8, 9);

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  Serial.println("Ready!");
}

void loop() {
  sensors_event_t a, g, t;
  mpu.getEvent(&a, &g, &t);

  // Read potentiometer
  int raw = analogRead(POT_PIN);
  int duty = raw / 16;

  if (duty > 255) {
    duty = 255;
  }

  // UP = enabled, sideways/down = disabled
  bool enabled = a.acceleration.z > TILT_THRESHOLD;

  // LED only works when tilt is enabled
  analogWrite(LED_PIN, enabled ? duty : 0);

  Serial.printf(
    "X %.2f  Y %.2f  Z %.2f | raw %4d -> duty %3d | %s\n",
    a.acceleration.x,
    a.acceleration.y,
    a.acceleration.z,
    raw,
    duty,
    enabled ? "ENABLED" : "OFF"
  );

  delay(20);
}