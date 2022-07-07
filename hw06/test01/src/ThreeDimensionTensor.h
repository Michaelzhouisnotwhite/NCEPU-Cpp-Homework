//
// Created by pce on 2021/3/31.
//

#ifndef TEST02_THREEDIMENSIONTENSOR_H
#define TEST02_THREEDIMENSIONTENSOR_H


#include "header.h"
class ThreeDimensionTensor {
    double x{}, y{}, z{};
public:
    ThreeDimensionTensor() = default;
    ThreeDimensionTensor(double, double, double);
    ThreeDimensionTensor operator+(const ThreeDimensionTensor&) const;
    friend ThreeDimensionTensor operator-(const ThreeDimensionTensor&, const ThreeDimensionTensor&);
    friend ostream &operator<<(ostream &out, ThreeDimensionTensor &t);
    double getX() const;
    double getY() const;
    double getZ() const;
    double setX(double );
    double setY(double );
    double setZ(double );
};


#endif //TEST02_THREEDIMENSIONTENSOR_H
