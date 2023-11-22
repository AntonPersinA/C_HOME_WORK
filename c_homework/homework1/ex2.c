#include <stdio.h>


int array_zero1(int *mas, size_t len_mas) {
    int i, count_zero = 0;
    for (i = 0; i < len_mas; ++i) {
        if (mas[i] == 0) {
            count_zero++;
        }
    }
    return count_zero;
}