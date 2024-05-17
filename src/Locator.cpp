#include "Locator.h"
#include "SweepingState.h"

Locator::Locator(IDistanceSensor *distSensor, IGyro *gyro, Servo *servo) {
  m_distSensor = distSensor;
  m_gyro = gyro;
  m_servo = servo;
  m_locState = new SweepingState(this);
} 

void Locator::start() {
  m_locState->handle();
}