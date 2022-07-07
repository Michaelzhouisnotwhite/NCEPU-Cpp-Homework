#include <iostream>
using namespace std;
class ComplexNum
{
    double real, imagi;
    char sym;
public:
    ComplexNum(double r, double i): real(r), imagi(i) 
    {
        this->sym = ((this->imagi) >= 0)? '+': '-';
    }
    void setComplx(double real, double imagi)
    {   
        this->real = real;
        this->imagi = imagi;

        this->sym = ((this->imagi) >= 0)? '+': '-';
    }

    char getSym() {return sym;}
    double getReal() {return real;}
    double getImagi() {return imagi < 0? -(this->imagi): this->imagi;}
    double getTImagi() {return this->imagi;}

    ComplexNum(const ComplexNum &complx)
    {
        real = complx.real;
        imagi = complx.imagi;
        sym = complx.sym;

        cout << "Copy completed!" << endl;
    }
};
int main()
{
    ComplexNum c1(1, -2);
    ComplexNum c2(c1);

    cout << "c1: " << c1.getReal() << " " << c1.getSym() << " " << c1.getImagi() << "i" << endl; 
    cout << "c2: " << c2.getReal() << " " << c2.getSym() << " " << c2.getImagi() << "i" << endl; 
    system("pause");
    return 0;
}