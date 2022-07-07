#include <iostream>
#include "Compare.h"
using namespace std;

int main()
{
    {
        int a = 1, b = 2;
        Compare<int> c(a, b);
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "the minimize of a and b: " << c.Min() << endl;
        cout << "the maximize of a and b: " << c.Max() << endl;
    }
    {
        double a = 3.14, b = 1.1;
        Compare<double> c(a, b);
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "the minimize of a and b: " << c.Min() << endl;
        cout << "the maximize of a and b: " << c.Max() << endl;
    }
	system("pause");
	
	return 0;
}