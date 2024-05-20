#include "SweepingState.h"


void SweepingState::handle() {
  Servo *servo = m_loc->getServo();
  IDistanceSensor *distSensor = m_loc->getDistanceSensor();
  LocatorConfig *locConfig = m_loc->getLocatorConfig();
  while(true) {
    int16_t pos;
    
    for (pos = locConfig->servoStartingPos; pos <= locConfig->rotationBoundary; pos += 1) {
      onRotationChange(pos, locConfig, distSensor, servo);
    }

    for (pos = locConfig->rotationBoundary; pos >= 0; pos -= 1) {
      onRotationChange(pos, locConfig, distSensor, servo);
    }
  }
}

void SweepingState::onRotationChange(uint16_t pos, LocatorConfig *locConfig, 
IDistanceSensor *distSensor, Servo *servo) {
    servo->write(pos);
    if(isInRange(locConfig, distSensor)) {
      FixatedState *newState = new FixatedState(m_loc);
      m_loc->setState(newState);
      newState->handle();

    }
}