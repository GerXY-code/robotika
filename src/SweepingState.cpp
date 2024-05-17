#include "SweepingState.h"

void SweepingState::handle() {
  Servo *servo = m_loc->getServo();
  IDistanceSensor *distSensor = m_loc->getDistanceSensor();
  while(true) {
    int16_t pos;
    uint16_t servoStartingPos = 0;
    uint16_t boundary = 180;
    for (pos = servoStartingPos; pos <= boundary; pos += 1) {
      servo->write(pos);
      delay(15);
    }
    for (pos = boundary; pos >= 0; pos -= 1) {
      servo->write(pos);              
      delay(15);                     
    }
    delay(300);
  }
}