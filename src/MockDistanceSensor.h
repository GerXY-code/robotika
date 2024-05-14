#ifndef MOCKDISTANCESENSOR
#define MOCKDISTANCESENSOR
#include "IDistanceSensor.h"

class MockDistanceSensor : public IDistanceSensor {
  public: 
    uint16_t getDistanceInCm() {
      return random(5, 100);
    }
};

#endif