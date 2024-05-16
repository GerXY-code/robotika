#ifndef MOCKDISTANCESENSOR
#define MOCKDISTANCESENSOR
#include "IDistanceSensor.h"

class MockDistanceSensor : public IDistanceSensor {
  public: 
    uint16_t getDistanceInCm() override {
      return random(5, 100);
    }
};

#endif