#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
#include "Arduino.h"

class DistanceSensor {
  public:
    virtual ~DistanceSensor() {};
    virtual uint16_t getDistanceInCm() = 0;
};

#endif