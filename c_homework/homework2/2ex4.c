#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void swap_value_or(int *number1, int *number2)
{
    if (number1!=number2)
    {
        *number1 ^= *number2;
        *number2 ^= *number1;
        *number1 ^= *number2;
    }
}


void print_array(int *mas, int length)
{
    printf("{");
    for (int i = 0; i<length; i++){
        printf("%d, ", mas[i]);
    }
    printf("\b\b}\n");
}


//Переменная limit ставит предел генерируемого значения, если стоит ноль, то limit определяется функцией rand()
void fill_mas_rand(int*mas, int len, int limit)
{
    srand(clock());
    if (limit)
    {
        limit++;
        for (int i = 0; i < len; i++)
        {
            *(mas + i) = rand() % (limit);
        }
    }
    else
    {
        limit++;
        for (int i = 0; i < len; i++)
        {
            *(mas + i) = rand();
        }
    }
}