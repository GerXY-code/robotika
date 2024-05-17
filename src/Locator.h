#ifndef LOCATOR_H
#define LOCATOR_H
#include <Servo.h>
#include "Arduino.h"
#include "IGyro.h"
#include "IDistanceSensor.h"
#include "LocatorState.h"

class LocatorState;

class Locator {
  private:
    IDistanceSensor *m_distSensor;
    IGyro *m_gyro;
    Servo *m_servo;
    LocatorState *m_locState;
  public:
    Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo);
    ~Locator() {
      delete m_distSensor; 
      delete m_gyro;
      delete m_servo;
    }
    void setState(LocatorState *locState) {
      m_locState = locState;
    }
    IDistanceSensor *getDistanceSensor() {
      return m_distSensor;
    }
    IGyro *getGyro() {
      return m_gyro;
    }
    Servo *getServo() {
      return m_servo;
    }
    void start();
  };

#endif