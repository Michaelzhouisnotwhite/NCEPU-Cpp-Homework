#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle {
protected:
    double width, length;
    double area, perimeter; 
public:
    Rectangle(double w, double len): width(w), length(len) {}
    double getArea();
    double getPerimeter();
};

double Rectangle::getArea() {   
    return width * length;
}

double Rectangle::getPerimeter() {
    return (width + length) * 2;
}

class Cuboid: public Rectangle {
    double height;
public:
    Cuboid(double w, double len, double h): Rectangle(w, len), height(h) {}
    double getVolume();
};

double Cuboid::getVolume() {
    return width * height * length;
}

int main() 
{
    Rectangle r(1.2, 2.3);
    Cuboid c(1, 2, 2.3);

    cout << "The Area of the rectangle: " << r.getArea() << endl;
    cout << "The Perimeter of the rectangle: " << r.getPerimeter() << endl;
    cout << "---------------------------------" << endl;
    cout << "The Volume of the cuboid: " << c.getVolume() << endl;
    system("pause");
    return 0;
}