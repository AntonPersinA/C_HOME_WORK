#include <stdlib.h>
#include <stdio.h>

int sum_num1(int num)
{
    int count = 0;
    num = abs(num);
    while (num)
    {
        count += num % 10;
        num /= 10;
    }
    return count;
}


int luck_ticket1()
{
    int mas[27] = {0};
    int i = 0;
    int count = 0;
    for (i = 0; i < 1000; ++i)
    {
        mas[sum_num1(i)] += 1;
    }
    for (i = 0; i <= (sizeof(mas) / sizeof(mas[0])) / 2; ++i)
    {
        count += mas[i] * mas[i];
    }
    return count * 2;
}