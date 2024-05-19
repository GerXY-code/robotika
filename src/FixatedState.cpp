#include "FixatedState.h"
#include "Led.h"

void FixatedState::handle() {

  IDistanceSensor *distSensor = m_loc->getDistanceSensor();
  LocatorConfig *locConfig = m_loc->getLocatorConfig();
  

   while(true) {
     switchLedState(4,1);
     if(!isInRange(locConfig, distSensor)) {
        switchLedState(4,0);
        SweepingState *newState = new SweepingState(m_loc);
        m_loc->setState(newState);
        newState->handle();
     }
     
     delay(15);
   }
}