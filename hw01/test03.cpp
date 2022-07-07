//
// Created by pce on 2021/3/7.
//

#include <iostream>

using namespace std;
struct Complex_No {
    double real;
    double imaginary;
};

int Exchange(Complex_No &, Complex_No &);

int main() {

    Complex_No com_1 = { 3,1};
    Complex_No com_2 = { 4.1,3.14};


    cout << "Before exchange :" << endl;
    cout << com_1.real << " + " << com_1.imaginary << "i" << endl;
    cout << com_2.real << " + " << com_2.imaginary << "i" << endl;

    Exchange(com_1, com_2);
    cout << "After exchange :" << endl;
    cout << com_1.real << " + " << com_1.imaginary << "i" << endl;
    cout << com_2.real << " + " << com_2.imaginary << "i" << endl;
    return 0;
}

int Exchange(Complex_No &p1, Complex_No &p2) {
    Complex_No temp = p1;
    p1 = p2;
    p2 = temp;
    return 0;
}
