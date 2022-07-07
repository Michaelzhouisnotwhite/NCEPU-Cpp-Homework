#include "header.h"
#include "ThreeDimensionTensor.h"
int main()
{
    ThreeDimensionTensor t1(1, 2, 3);
    ThreeDimensionTensor t2(2, 3, 4);
    ThreeDimensionTensor t3, t4, t5;
    t3 = t1 + t2;
    t4 = t1 - t2;
    t5 = t2 - t1;
	cout << t1 << " + " << t2 << " = " << t3 << endl;
	cout << t1 << " - " << t2 << " = " << t4 << endl;
	cout << t2 << " - " << t1 << " = " << t5 << endl;
	system("pause");
    return 0;
}
