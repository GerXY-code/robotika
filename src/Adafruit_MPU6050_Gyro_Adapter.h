#ifndef ADAFRUIT_MPU6050_GYRO_ADAPTER
#define ADAFRUIT_MPU6050_GYRO_ADAPTER
#include "IGyro.h"
#include "Adafruit_MPU6050.h"

class Adafruit_MPU6050_Gyro_Adapter : public IGyro { 
  private:
    Adafruit_MPU6050_Gyro *m_gyro;
    sensors_event_t* m_event; 
    void updateEvent();
  public:
    Adafruit_MPU6050_Gyro_Adapter(Adafruit_MPU6050_Gyro *gyro) {
      m_gyro = gyro;
      m_event = new sensors_event_t;
    }
    ~Adafruit_MPU6050_Gyro_Adapter() {
      delete m_gyro;
    }
    float getRotationX() override;
    float getRotationY() override;
    float getRotationZ() override;
};

#endif