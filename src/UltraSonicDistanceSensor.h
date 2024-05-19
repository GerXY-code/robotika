#ifndef ULTRASONICDISTANCESENSOR
#define ULTRASONICDISTANCESENSOR
#include "IDistanceSensor.h"

class UltraSonicDistanceSensor : public IDistanceSensor {
  private:
    uint8_t m_pinTrig;
    uint8_t m_pinEcho;
  public: 
    UltraSonicDistanceSensor(uint8_t pinTrig, uint8_t pinEcho);
    uint16_t getTargetDistanceInCm() override;
};

#endif