#include "Led.h"

void switchLedState(uint8_t pin, uint8_t value) {
  digitalWrite(pin,value);
}