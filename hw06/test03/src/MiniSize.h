#include "header.h"
template<typename type>
type MiniSize(type *array, int len) {
    type min = *array;
    for (int i = 0; i < (len); i++) {
        if (array[i] < min) {
           min = array[i];
        }
    }
    return min;
}