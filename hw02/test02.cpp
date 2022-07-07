#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int no;
    string name;
    double gpa;
public:
    Student() {}
    Student(int no, string name, double gpa): no(no), name(name), gpa(gpa) {}
    void setInfo(int no, string name, double gpa)
    {
        this->no = no;
        this->name = name;
        this->gpa = gpa;
    }
    void prettyOutput()
    {
        cout << " ---------------" << endl;
        cout << "|" << " " << "No:\t" << no << "\t|" << endl;
        cout << "|" << " " << "Name:\t" << name << "\t|" << endl;
        cout << "|" << " " << "GPA:\t" << gpa << "\t|" << endl;
        cout << " ---------------" << endl;
    }
};
int main()
{
    Student stu_1, stu_2;
    stu_1.setInfo(1, "Michael", 4.9);
    stu_2.setInfo(2, "Jack", 3.8);

    stu_1.prettyOutput();
    stu_2.prettyOutput();
    system("pause");
    return 0;
}