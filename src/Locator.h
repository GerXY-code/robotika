#ifndef LOCATOR_H
#define LOCATOR_H
#include <Servo.h>
#include "Gyro.h"
#include "IDistanceSensor.h"

class Locator {
  private:
    IDistanceSensor *m_distSensor;
    Gyro *m_gyro;
    Servo *m_servo;
  public: 
    Locator(IDistanceSensor *distSensor, Gyro *gyro, Servo *servo) {
      m_distSensor = distSensor;
      m_gyro = gyro;
      m_servo = servo;
    }
    ~Locator() {
      delete m_distSensor; 
      delete m_gyro;
      delete m_servo;
    }
    void sweep(uint16_t servo_starting_pos, uint16_t boundaryToLeft, uint16_t boundaryToRight);
};

#endif