#include "Adafruit_MPU6050_Gyro_Adapter.h"

void Adafruit_MPU6050_Gyro_Adapter::updateEvent() {
  m_gyro->getEvent(m_event);
}

float Adafruit_MPU6050_Gyro_Adapter::getRotationX() {
  updateEvent();
  return m_event->gyro.x;
}

float Adafruit_MPU6050_Gyro_Adapter::getRotationY() {
  updateEvent();
  return m_event->gyro.y;
}

float Adafruit_MPU6050_Gyro_Adapter::getRotationZ() {
  updateEvent();
  return m_event->gyro.z;
}