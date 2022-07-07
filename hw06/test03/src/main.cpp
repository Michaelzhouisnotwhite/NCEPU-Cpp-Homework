#include "header.h"
#include "MiniSize.h"
using namespace std;
int main()
{
	int a[] = {1, 2, 0};
	double b[] = {1.2, 2.0, 8, -9, -9.1};
	
	string str = typeid(*b).name();
	cout << typeid(*b).name() << endl;
	int len_a = sizeof(a) / sizeof(typeid(*a).name());
	int len_b = sizeof(b) / sizeof(typeid(*b).name());
	cout << MiniSize(a, len_a) << endl;
	cout << MiniSize(b, len_b) << endl;
	system("pause");
	
	return 0;
}