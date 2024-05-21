#include "FixatedState.h"
#include "Led.h"

void FixatedState::handle() {
  Servo *servo = m_loc->getServo();
  IDistanceSensor *distSensor = m_loc->getDistanceSensor();
  LocatorConfig *locConfig = m_loc->getLocatorConfig();
  IGyro *gyro = m_loc->getGyro();
  while(isTargetInRange(locConfig, distSensor)) {
    switchLedState(4,1);
    float gyroZ = gyro->getRotationZ();
    if (abs(gyroZ) >= locConfig->rotationThreshold) {
      const int16_t newPos = gyroZ > 0 ? --m_currentPos : ++m_currentPos;
      checkCurrentPos(newPos, gyroZ, locConfig->rotationBoundary);
      servo->write(m_currentPos);
      gyroZ = gyro->getRotationZ();
      delay(calculateServoRotationDelayFromGyroZ(locConfig, gyroZ));
    }
  }
  switchLedState(4,0);
  SweepingState *newState = new SweepingState(m_loc, m_currentPos);
  m_loc->setState(newState);
  newState->handle();
}

void FixatedState::checkCurrentPos(int16_t newPos, float gyroZ, uint16_t rotationBoundary) {
  if (newPos < 0) {
    m_currentPos = 0;
  } else if (newPos > rotationBoundary) {
    m_currentPos = rotationBoundary;
  }
}