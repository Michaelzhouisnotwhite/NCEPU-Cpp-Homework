#include <iostream>
using namespace std;

class Rect 
{
private:
    double a, b;
public:
    Rect(double a=0, double b=0):a(a), b(b) {}
    void Set_ab(double x, double y) 
    {
        a = x; b = y;
    }
    double GetArea() 
    {
        return a * b;
    }
    double GetPerimeter() 
    {
        return (a + b) * 2;
    }
        
};
int main() 
{
    Rect r1, r2(1), r3(2, 3);
    system("pause");
    return 0;
}