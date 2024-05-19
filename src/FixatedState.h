#ifndef FIXATED_STATE
#define FIXATED_STATE
#include "LocatorState.h"
#include "DistanceUtil.h"
#include "SweepingState.h"

class FixatedState : public LocatorState {
  public:
    FixatedState(Locator *loc) : LocatorState(loc) {}
    void handle() override;
};

#endif