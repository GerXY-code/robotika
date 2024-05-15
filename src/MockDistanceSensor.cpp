#include "MockDistanceSensor.h"

uint16_t MockDistanceSensor::getDistanceInCm() {
  return random(5, 50);
}
