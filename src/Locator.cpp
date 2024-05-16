#include "Locator.h"

void Locator::sweep(uint16_t servoStartingPos, uint16_t boundary) {
  int16_t pos;
  for (pos = servoStartingPos; pos <= boundary; pos += 1) {
    m_servo->write(pos);
    delay(15);
  }
  for (pos = boundary; pos >= 0; pos -= 1) {
    m_servo->write(pos);              
    delay(15);                     
  }
}