//
// Created by pce on 2021/3/7.
//

#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
    int no;
    cout << "Enter the Number of integers:" << endl;
    cin >> no;
    int *integers = new int[no];

    cout << "Enter each integer:" << endl;
    for (int i = 0; i < no; ++i) {
        cin >> integers[i];
    }

    for (int i = 0; i < no - 1; ++i) {
        for (int j = 0; j < no - i - 1; ++j) {
            if (integers[j] > integers[j + 1]) {
                int temp = integers[j + 1];
                integers[j + 1] = integers[j];
                integers[j] = temp;
            }
        }
    }

    cout << "The sorting result is:" << endl;
    for (int *p = integers; p < &integers[no]; ++p) {
        cout << *p << endl;
    }

    delete[] integers;
    system("pause");
    return 0.;
}