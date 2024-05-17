#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include <Servo.h>
#include "Locator.h"
#include "UltraSonicDistanceSensor.h"
#include "Adafruit_MPU6050_Gyro_Adapter.h"

#define SERVO_STARTING_POS 0
#define PIN_ECHO 2
#define PIN_TRIG 3
#define PIN_SERVO 9

Adafruit_MPU6050 mpu;
IDistanceSensor *distSensor = new UltraSonicDistanceSensor(PIN_TRIG, PIN_ECHO);
Servo servo;
IGyro *gyro = NULL;
Locator *locator = NULL;

void setup(void) {
  Serial.begin(115200);
  while (!mpu.begin()) {
    Serial.println("MPU6050 not connected!");
    delay(1000);
  }
  Serial.println("MPU6050 ready!");
  servo.attach(PIN_SERVO);
  gyro = new Adafruit_MPU6050_Gyro_Adapter(mpu.getGyroSensor());
  locator = new Locator(distSensor, gyro, &servo);
  locator->start();
}

void loop() {
}

