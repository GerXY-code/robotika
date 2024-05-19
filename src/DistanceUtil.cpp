#include "DistanceUtil.h"

bool isInRange(LocatorConfig *config, IDistanceSensor *distSensor) {
  const uint16_t value = distSensor->getTargetDistanceInCm();
  return value >= config->distanceRangeMin && value <= config->distanceRangeMax;
}