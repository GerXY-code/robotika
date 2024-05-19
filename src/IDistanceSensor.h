#ifndef IDISTANCESENSOR_H
#define IDISTANCESENSOR_H
#include "Arduino.h"

class IDistanceSensor {
  public:
    virtual ~IDistanceSensor() {};
    virtual uint16_t getTargetDistanceInCm() = 0;
};

#endif