#include "Locator.h"
#include "SweepingState.h"

#define DEFAULT_SERVO_STARTING_POS 0
#define DEFAULT_ROTATION_BOUNDARY 180
#define DEFAULT_MIN_DISTANCE_RANGE 2
#define DEFAULT_MAX_DISTANCE_RANGE 50

LocatorConfig defaultLocConfig = {
  DEFAULT_SERVO_STARTING_POS,
  DEFAULT_ROTATION_BOUNDARY,
  DEFAULT_MIN_DISTANCE_RANGE,
  DEFAULT_MAX_DISTANCE_RANGE
};

Locator::Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo) : Locator(distSensor, gyro, servo, &defaultLocConfig) {}

Locator::Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo, LocatorConfig *locConfig) {
  m_distSensor = distSensor;
  m_gyro = gyro;
  m_servo = servo;
  m_locState = new SweepingState(this, locConfig->servoStartingPos);
  m_locConfig = locConfig;
}

void Locator::start() {
  m_locState->handle();
}