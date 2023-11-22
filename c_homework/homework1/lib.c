#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>




void swap_value(int *number1, int *number2)
{
    if (number1!=number2) {
        *number1 ^= *number2;
        *number2 ^= *number1;
        *number1 ^= *number2;
    }
}


int array_zero(int *mas, size_t len_mas)
{
    int i, count_zero = 0;
    for (i = 0; i < len_mas; ++i) {
        if (mas[i] == 0) {
            count_zero++;
        }
    }
    return count_zero;
}


int remainder1(int divider, int denominator)
{
    if (!denominator) {
        printf("ZeroDivisionError: integer division or modulo by zero");
        return 0;
    }
    if (denominator == -1 || denominator == 1) {
        return 0;
    }
    else {
        if (divider > 0 && denominator > 0) {
            while (divider >= denominator) {
                divider -= denominator;
            }
            return divider;
        }
        if (divider < 0 && denominator > 0) {
            while (divider < 0) {
                divider += denominator;
            }
            return divider;
        }
        if (divider < 0 && denominator < 0) {
            while (divider >= denominator && divider < 0) {
                divider -= denominator;

            }
            return divider;
        }
        if (divider > 0 && denominator < 0) {
            while (divider>0) {
                divider += denominator;
            }
            return divider;
        }
    }
}


int sum_num(int num)
{
    int count = 0;
    num = abs(num);
    while (num) {
        count += num % 10;
        num /= 10;
    }
    return count;
}


int luck_ticket()
{
    int mas[27] = {0}, i, count = 0;
    for (i = 0; i < 1000; ++i) {
        mas[sum_num(i)] += 1;
    }
    for (i = 0; i <= (sizeof(mas) / sizeof(mas[0])) / 2; ++i)
        count += mas[i] * mas[i];
    return count * 2;
}


int parenthesis_rule(char *stroka)
{
    int skobe = 0, i = 0;
    while (*(stroka+i) != *"\0") {
        if (*(stroka+i) == *"(" || *(stroka+i) == *"[" || *(stroka+i) == *"{"){
            skobe++;
        }
        if (*(stroka+i) == *")" || *(stroka+i) == *"]" || *(stroka+i) == *"}"){
            skobe--;
            if (skobe <0)
                return 0;
        }
        ++i;
    }
    return !skobe;
}


void print_array(int *mas, int length)
{
    printf("{");
    for (int i = 0; i<length; i++){
        printf("%d, ", mas[i]);
    }
    printf("\b\b}\n");
}


int is_it_prime(int num)
{
    num = abs(num);
    if (num <=1)
        return 0;
    int i;
    double power = pow((float)num, 0.5);
    for (i = 2; i<=power*1; ++i){
        if (num%i==0){
            return 0;
        }
    }
    return 1;
}


void print_prime_before(int num_before)
{
    num_before = abs(num_before);
    printf("{");
    for (int i = 2; i<=num_before; ++i){
        if (is_it_prime(i) == 1){
            printf("%d, ", i);
        }
    }
    printf("\b\b}");
}


int str_in_str(char *stroka1, char *stroka2)
{
    if (strlen(stroka1) > strlen(stroka2) || (*stroka2 == *"") || (*stroka1 == *""))
        return 0;
    int i, g, flag, count = 0;
    for (g = 0; g <= strlen(stroka2) - strlen(stroka1); ++g) {
        flag = 1;
        for (i = 0; i < (strlen(stroka1)); ++i) {
            if (*(stroka1 + i) != *(stroka2 + g + i)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            count++;
        }
    }
    return count;
}


void swap_value_or(int *number1, int *number2)
{
    if (number1!=number2) {
        *number1 ^= *number2;
        *number2 ^= *number1;
        *number1 ^= *number2;
    }
}


int *array_reverse(int *mas, int a, int b) //не включительно
{
    int help = 0;
    b--;
    for (a; a<b; a++) {
        if (a >= b-help){
            return mas;
        }
        swap_value_or((mas + a), (mas + b - help));
        help+=1;
    }
    return mas;
}


int compare_array(int *mas1, int *mas2, int len)
{
    for (int i = 0; i < len; ++i){
        if (*(mas1 + i) != *(mas2 + i))
        {
            return 0;
        }
    }
    return 1;
}