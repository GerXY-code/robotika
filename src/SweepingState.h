#ifndef SWEEPINGSTATE
#define SWEEPINGSTATE
#include "LocatorState.h"

class SweepingState : public LocatorState {
  public:
    SweepingState(Locator *loc) : LocatorState(loc) {}
    void handle() override;
};

#endif