#include "Locator.h"
#include "Arduino.h"

void Locator::sweep(uint16_t servoStartingPos, uint16_t boundaryToLeft, uint16_t boundaryToRight) {
  uint16_t i = servoStartingPos;
  while (i < boundaryToRight) {
    m_servo->write(i);
    i++;
    delay(15);
  }
  while (i > 0) {
    m_servo->write(i);
    i--;
    delay(15);
  }
}