#ifndef DISTANCE_UTIL
#define DISTANCE_UTIL
#include "Locator.h"
#include "IDistanceSensor.h"

bool isInRange(LocatorConfig *config, IDistanceSensor *distSensor);

#endif