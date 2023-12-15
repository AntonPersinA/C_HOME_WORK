#include <stdio.h>


int array_zero1(int *mas, size_t len_mas)
{
    int i = 0;
    int count_zero = 0;
    for (; i < len_mas; ++i)
    {
        if (mas[i] == 0)
        {
            count_zero++;
        }
    }
    return count_zero;
}