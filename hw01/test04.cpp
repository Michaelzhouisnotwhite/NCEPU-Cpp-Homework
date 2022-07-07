//
// Created by pce on 2021/3/7.
//
#include <iostream>
using namespace std;
short Abs(short );
int Abs(int );
double Abs(double );
int main() {
    cout << "---Test Override---" << endl;
    {
        cout << "Enter short int:";
        short a;
        cin >> a;
        cout << Abs(a) << endl;
    }
    cout << "----------" << endl;
    {
        cout << "Enter  int:";
        int a;
        cin >> a;
        cout << Abs(a) << endl;
    }
    cout << "----------" << endl;
    {
        cout << "Enter double:";
        double a;
        cin >> a;
        cout << Abs(a) << endl;
    }

    return 0;
}
short Abs(short a) {
    if (a < 0) a *= -1;
    return a;
}
int Abs(int a) {
    return abs(a);
}
double Abs(double a) {
    if (a < 0) a *= -1;
    return a;
}