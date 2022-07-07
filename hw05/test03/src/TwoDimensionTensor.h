//
// Created by pce on 2021/4/1.
//

#ifndef TEST03_TWODIMENSIONTENSOR_H
#define TEST03_TWODIMENSIONTENSOR_H


class TwoDimensionTensor {
    double x{}, y{};
public:
    TwoDimensionTensor(double x, double y);
    double getX() const;
    double getY() const;
    double operator* (TwoDimensionTensor &t) const;
    friend ostream &operator<< (ostream &out, TwoDimensionTensor &t);
};


#endif //TEST03_TWODIMENSIONTENSOR_H
