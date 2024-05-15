#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>
#include "Locator.h"
#include "MockDistanceSensor.h"

#define PIN_SERVO 9
#define SERVO_STARTING_POS 0
#define PIN_TRIG 3
#define PIN_ECHO 2

Adafruit_MPU6050 mpu;
sensors_event_t event;
IDistanceSensor* distSensor = new MockDistanceSensor();
Gyro gyro;
Servo servo;
Locator *locator = new Locator(distSensor, &gyro, &servo);

void setup(void) {
  Serial.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  servo.attach(PIN_SERVO);
  while (!mpu.begin()) {
    Serial.println("MPU6050 not connected!");
    delay(1000);
  }
  Serial.println("MPU6050 ready!");
}

void loop() {
  mpu.getGyroSensor()->getEvent(&event);
  Serial.println(distSensor->getDistanceInCm());
  //event.gyro.z
  delay(100);
}

