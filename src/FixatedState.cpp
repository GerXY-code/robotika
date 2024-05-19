#include "FixatedState.h"

void FixatedState::handle() {

  IDistanceSensor *distSensor = m_loc->getDistanceSensor();
  LocatorConfig *locConfig = m_loc->getLocatorConfig();

   while(true) {
     if(!isInRange(locConfig, distSensor)) {
        SweepingState *newState = new SweepingState(m_loc);
        m_loc->setState(newState);
        newState->handle();
     }
     
     delay(15);
   }
}