#ifndef FIXATED_STATE
#define FIXATED_STATE
#include "LocatorState.h"
#include "SweepingState.h"
#include "Util.h"

class FixatedState : public LocatorState {
  private:
    int16_t m_currentPos;
  public:
    FixatedState(Locator *loc, uint16_t startingPos) : LocatorState(loc) {
      m_currentPos = startingPos;
    }
    void handle() override;
    void checkCurrentPos(int16_t newPos, float gyroZ, uint16_t rotationBoundary);
};

#endif