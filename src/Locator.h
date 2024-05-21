#ifndef LOCATOR_H
#define LOCATOR_H
#include <Servo.h>
#include "Arduino.h"
#include "IGyro.h"
#include "IDistanceSensor.h"
#include "LocatorState.h"

class LocatorState;

struct LocatorConfig {
  const float rotationThreshold;
  const uint16_t rotationBoundary;
  const uint16_t distanceRangeMin;
  const uint16_t distanceRangeMax;
  const uint16_t servoStartingPos;
  LocatorConfig(float rT, uint16_t sSPos, uint16_t rB, uint16_t dRMin, uint16_t dRMax): 
    rotationThreshold(rT), servoStartingPos(sSPos), rotationBoundary(rB), distanceRangeMin(dRMin), distanceRangeMax(dRMax){}
  LocatorConfig& operator=(const LocatorConfig&) = delete;
};

class Locator {
  private:
    IDistanceSensor *m_distSensor;
    IGyro *m_gyro;
    Servo *m_servo;
    LocatorState *m_locState;
    LocatorConfig *m_locConfig;
  public:
    Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo);
    Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo, LocatorConfig *locConfig);
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
    LocatorConfig *getLocatorConfig() {
      return m_locConfig;
    }
    void start();
  };

#endif