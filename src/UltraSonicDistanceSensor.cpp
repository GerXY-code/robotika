#include "UltraSonicDistanceSensor.h"
#include "Arduino.h"

UltraSonicDistanceSensor::UltraSonicDistanceSensor(uint8_t pinTrig, uint8_t pinEcho) {
  m_pinTrig = pinTrig;
  m_pinEcho = pinEcho;
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

uint16_t UltraSonicDistanceSensor::getDistanceInCm() {
  digitalWrite(m_pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(m_pinTrig, LOW);

  int duration = pulseIn(m_pinEcho, HIGH);
  return duration / 58;
}