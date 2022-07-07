//
// Created by pce on 2021/3/31.
//

#include "ThreeDimensionTensor.h"

ThreeDimensionTensor::ThreeDimensionTensor(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

ThreeDimensionTensor ThreeDimensionTensor::operator+(const ThreeDimensionTensor & T) const {
    ThreeDimensionTensor TT(T.getX() + this->x, T.getY() + this->y, T.getZ() + this->z);
    return TT;
}

ThreeDimensionTensor ThreeDimensionTensor::operator-(const ThreeDimensionTensor & T) const  {
    ThreeDimensionTensor TT(this->x - T.getX(), this->y - T.getY(), this->z - T.getZ());
    return TT;
}

double ThreeDimensionTensor::getX() const {
    return x;
}

double ThreeDimensionTensor::getY() const {
    return y;
}

double ThreeDimensionTensor::getZ() const {
    return z;
}

double ThreeDimensionTensor::setX(double d) {
    this->x = d;
    return 0;
}

double ThreeDimensionTensor::setY(double d) {
    this->y = d;
    return 0;
}

double ThreeDimensionTensor::setZ(double d) {
    this->z = d;
    return 0;
}

ostream &operator<< (ostream &out, ThreeDimensionTensor &t) {
    out << "["
    << t.getX() << ", " << t.getY() << ", " << t.getZ()
    <<"]";
    return out;
} 

