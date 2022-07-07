#include "header.h"
#include "TwoDimensionTensor.h"
// int main() {
//     TwoDimensionTensor t1(1, 1);
//     TwoDimensionTensor t2(4, 5);
//     double z = t1 * t2;
//     cout << t1 << " * " << t2 << " = " << z;
//     cout.put('\n');
//     system("pause");
//     return 0;
// }

int main()
{
    TwoDimensionTensor t1(1, 1);
    TwoDimensionTensor t2(4, 5);
    double z = t1 * t2;
    cout << t1 << " * " << t2 << " = " << z;
    cout.put('\n');
    system("pause");
    return 0;
}
