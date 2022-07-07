#pragma once
#define MAXSIZE 100
template<typename T>
class Stack {
    T element[MAXSIZE];
    int count = -1;
public:
    Stack() {}
    Stack(T t) {
        push(t);
    }
    int init() {
        count = -1;
        element[MAXSIZE] = {};
        return 0;
    }
    int push(T t) {
        count ++;
        element[count] = t;
        return 0;
    }
    T pop() {
        T temp = element[count];
        count --;
        return temp;
    }
    int getCount() {
        return count + 1;
    }    
};