#ifndef LOCATORSTATE
#define LOCATORSTATE
#include "Locator.h"

class Locator;

class LocatorState {
  protected:
    Locator *m_loc;
    LocatorState(Locator *loc) {
      m_loc = loc;
    };
    ~LocatorState() {
      delete m_loc;
    };
  public:
    virtual void handle();
};

#endif