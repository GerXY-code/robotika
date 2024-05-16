#ifndef LOCATOR_H
#define LOCATOR_H
#include <Servo.h>
#include "Arduino.h"
#include "IGyro.h"
#include "IDistanceSensor.h"

class Locator {
  private:
    IDistanceSensor *m_distSensor;
    IGyro *m_gyro;
    Servo *m_servo;
  public: 
    Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo) {
      m_distSensor = distSensor;
      m_gyro = gyro;
      m_servo = servo;
    }
    ~Locator() {
      delete m_distSensor; 
      delete m_gyro;
      delete m_servo;
    }
    void sweep(uint16_t servoStartingPos, uint16_t boundary);
};

#endif