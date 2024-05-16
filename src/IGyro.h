#ifndef IGYRO_H
#define IGYRO_H

class IGyro {
  public:
    virtual ~IGyro() {};
    virtual float getRotationX() = 0;
    virtual float getRotationY() = 0;
    virtual float getRotationZ() = 0;
};

#endif