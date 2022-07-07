//
// Created by pce on 2021/4/1.
//
#include "header.h"
#include "TwoDimensionTensor.h"

TwoDimensionTensor::TwoDimensionTensor(double x, double y) {
    this->x = x;
    this->y = y;
}

double TwoDimensionTensor::getX() const {
    return x;
}

double TwoDimensionTensor::getY() const {
    return y;
}

double TwoDimensionTensor::operator* (TwoDimensionTensor &t) const {
    return sqrt((pow(this->getX() - t.getX(), 2) + pow(this->getY() - t.getY(), 2)));
}

ostream &operator<<(ostream &out, TwoDimensionTensor &t) {
    out << fixed << setprecision(2)
    << "("
    << t.getX() << ", " << t.getY()
    << ")";
    return out;
}

