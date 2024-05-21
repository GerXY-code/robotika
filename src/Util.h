#ifndef UTIL
#define UTIL
#include "Locator.h"
#include "IDistanceSensor.h"

bool isTargetInRange(LocatorConfig *config, IDistanceSensor *distSensor);

int16_t calculateServoRotationDelayFromGyroZ(LocatorConfig *config, float gyroZ);

#endif