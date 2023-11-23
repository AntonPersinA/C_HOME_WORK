//
// Created by anton on 22.11.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_hw4.h"


char *bin_str(int a)
{
    int minus = a < 0 ? 1 : 0;
    a = a < 0 ? -a : a;
    if (a > 123456789) {
        printf("bin_str error\n");
        a = 1;
    }
    if (a == 0) {
        char *str = calloc(2, sizeof(char));  // Выделяем пространство под '0' и окончание строки '\0'
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    int c = 1, i = 0;
    for (; c <= a; ++i) {
        c *= 2;
    }
    char *str = calloc(i + 3, sizeof(char)); //redo
    str[0] = (minus == 1) ? '1' : '0';
    c >>= 1;
    for (int j = 1; j < i + 1; ++j) {
        if (c <= a) {
            str[j] = '1';
            a -= c;
            c >>= 1;
        } else {
            str[j] = '0';
            c >>= 1;
        }
    }
    if (minus)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (str[j] == '0') {
                str[j] = '1';
            } else {
                str[j] = '0';
            }
        }
        for (int k = i; k >=0; --k)
        {
            if (str[k] == '0')
            {
                str[k] = '1';
                break;
            }
            else{
                str[k] = '0';
            }
        }
    }
    *(str + i + 1) = '\0';
    return str;
}


int bin_to_10(char *a)
{
    int ret = 0;
    int two = 1;
    if (a[0] == '1')
    {
        for (int i = (int)strlen(a) - 1; i > 0; --i)
        {
            if (a[i] == '0')
            {
                ret += two;
            }
            two *= 2;
        }
        return - ret - 1;
    }
    for (int i = (int)strlen(a) - 1; i > 0; --i)
    {
        if (a[i] != '0')
        {
            ret += two;
        }
        two *= 2;
    }
    return ret;
}


char *bin_add(char *a, char *b)
{
    int int_a = bin_to_10(a);
    int int_b = bin_to_10(b);

    char *c = bin_str(int_a + int_b);

    return c;
}