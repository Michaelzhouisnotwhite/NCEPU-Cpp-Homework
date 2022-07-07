#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle {
protected:
    double width, length;
    double area{}, perimeter{};
public:
    Rectangle(double w, double len): width(w), length(len) {}
    double getArea() const;
    double getPerimeter() const;
};

double Rectangle::getArea() const {
    return width * length;
}

double Rectangle::getPerimeter() const {
    return (width + length) * 2;
}

class Location {
    double x = 0, y = 0;
    double *locate = new double[2];
public:
    Location() = default;
    Location(double x, double y): x(x), y(y) {
        *locate = x;
        *(locate + 1) = y;
    }
    double* getLocation() {return locate;}
};

class Cuboid: public Rectangle {
protected:
    double height;
    Location lo;
public:
    Cuboid(double w, double len, double h, double x, double y): Rectangle(w, len), height(h) {
        Location locate(x, y);
        lo = locate;
    }
    double getVolume();
    double* getLocation();
};

double Cuboid::getVolume() {
    return width * height * length;
}

double* Cuboid::getLocation() {
    return lo.getLocation();
}

int main() 
{
    Cuboid cuboid(1, 2, 2.3, 2.99, 3.01);
    cout << "The Volume of the Cuboid: " << cuboid.getVolume() << endl;
    cout << "The Location of th Cuboid: ";
    cout << "(" << cuboid.getLocation()[0] << ", " << cuboid.getLocation()[1] << ")" << endl;
    system("pause");
    return 0;
}