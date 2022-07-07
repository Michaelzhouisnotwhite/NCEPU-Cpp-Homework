#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	char ch[] = "This is a string";
	Stack<char> st_ch;
	st_ch.init();
	for (int i = 0; i < (sizeof(ch) / sizeof(char)); i++) {
		st_ch.push(ch[i]);
	}

	for (int i = 0; i < (sizeof(ch) / sizeof(char)); i++) {
		cout << st_ch.pop();
	}
	cout.put('\n');

	double d[4] = {1.2, 3.14, 4.52, 0};
	Stack<double> dstack;
	dstack.init();
	for (int i = 0; i < 4; i++) {
		dstack.push(d[i]);
	}
	for (int i = 0; i < 4; i++) {
		cout << dstack.pop() << endl;
	}
	system("pause");
	return 0;
}