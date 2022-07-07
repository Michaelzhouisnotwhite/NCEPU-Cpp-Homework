#include <iostream>

using namespace std;

class Rect {
private:
    double a, b;
public:
    void Set_ab(double x, double y) {
        a = x; b = y;
    }
    double GetArea() {
        return a * b;
    }
    double GetPerimeter() {
        return (a + b) * 2;
    }
        
};
int main() {
    Rect r1, r2;

    r1.Set_ab(1.1, 1.2);
    r2.Set_ab(1, 2);

    cout << "Areas is: \t" << r1.GetArea() << ", \t" << r2.GetArea() << endl;
    cout << "Perimeter is: \t" << r1.GetPerimeter() << ", \t" << r2.GetPerimeter() << endl;
    system("pause");
    return 0;
}