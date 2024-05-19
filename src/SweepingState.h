#ifndef SWEEPINGSTATE
#define SWEEPINGSTATE
#include "LocatorState.h"
#include "IDistanceSensor.h"
#include "DistanceUtil.h"
#include "FixatedState.h"

class SweepingState : public LocatorState {
  public:
    SweepingState(Locator *loc) : LocatorState(loc) {}
    void handle() override;
  private:
    void onRotationChange(uint16_t pos, LocatorConfig *locConfig, 
    IDistanceSensor *distSensor, Servo *servo);
};

#endif