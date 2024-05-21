#ifndef SWEEPINGSTATE
#define SWEEPINGSTATE
#include "LocatorState.h"
#include "FixatedState.h"
#include "IDistanceSensor.h"
#include "Util.h"

class SweepingState : public LocatorState {
  private:
    uint16_t m_currentPos;
  public:
    SweepingState(Locator *loc, uint16_t startingPos) : LocatorState(loc) {
      m_currentPos = startingPos;
    }
    void handle() override;
};

#endif