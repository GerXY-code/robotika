#include "Util.h"

#define MAX_DELAY 10

bool isTargetInRange(LocatorConfig *config, IDistanceSensor *distSensor) {
  const uint16_t value = distSensor->getTargetDistanceInCm();
  return value > config->distanceRangeMin && value < config->distanceRangeMax;
}

int16_t calculateServoRotationDelayFromGyroZ(LocatorConfig *config, float gyroZ) {
  const float threshold = config->rotationThreshold;
  const float absGyroZ = abs(gyroZ);
  if (absGyroZ <= threshold) {
    return MAX_DELAY;
  }
  return int(MAX_DELAY / absGyroZ);  
}
