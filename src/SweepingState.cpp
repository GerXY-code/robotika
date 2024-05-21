#include "SweepingState.h"

void SweepingState::handle() {
  Servo *servo = m_loc->getServo();
  IDistanceSensor *distSensor = m_loc->getDistanceSensor();
  LocatorConfig *locConfig = m_loc->getLocatorConfig();
  while (m_currentPos < locConfig->rotationBoundary) {
    if (isTargetInRange(locConfig, distSensor)) {
      break;
    }
    servo->write(m_currentPos);
    m_currentPos++;
    delay(5);
  }
  while (m_currentPos > 0) {
    if (isTargetInRange(locConfig, distSensor)) {
      break;
    }
    servo->write(m_currentPos);
    m_currentPos--;
    delay(5);
  }
  FixatedState *newState = new FixatedState(m_loc, m_currentPos);
  m_loc->setState(newState);
  newState->handle();
}