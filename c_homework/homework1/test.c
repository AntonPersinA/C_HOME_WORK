#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int test_swap_value()
{
    {
        int a = 10, b = -10;
        int test_a = a, test_b = b;

        swap_value(&a, &b);

        if (a != test_b || b != test_a)
        {
            printf("test_swap_value error\n");
            return 0;
        }
    }

    return 1;
}


int test_array_zero()
{
    {
        int mas[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        if (array_zero(mas, 10) != 1)
        {
            printf("test_array_zero error\n");
            return 0;
        }
    }

    {
        int mas[5] = {0, 0, 0, 0, -0};

        if (array_zero(mas, 5) != 5)
        {
            printf("test_array_zero error\n");
            return 0;
        }
    }

    {
        int mas[5] = {1, 2, 3, -1, -6};

        if (array_zero(mas, 5) != 0)
        {
            printf("test_array_zero error\n");
            return 0;
        }
    }
    return 1;
}


int test_remainder1()
{
    {
        int divider = 78, denominator = 33;

        if (remainder1(divider, denominator) != 12)
        {
            printf("test_remainder1 error\n");
            return 0;
        }
    }

    {
        int divider = -78, denominator = 33;

        if (remainder1(divider, denominator) != 21)
        {
            printf("test_remainder1 error\n");
            return 0;
        }
    }

    {
        int divider = -9, denominator = -13;

        if (remainder1(divider, denominator) != 4)
        {
            printf("test_remainder1 error\n");
            return 0;
        }
    }

    {
        int divider = 9, denominator = 90;

        if (remainder1(divider, denominator) != 9)
        {
            printf("test_remainder1 error\n");
            return 0;
        }
    }

    {
        int divider = 78, denominator = 26;

        if (remainder1(divider, denominator) != 0)
        {
            printf("test_remainder1 error\n");
            return 0;
        }
    }

    return 1;
}


int test_sum_num()
{
    {
        int a = 0;

        if (sum_num(a) != 0)
        {
            printf("test_sum_num error\n");
            return 0;
        }
    }

    {
        int a = 23123;

        if (sum_num(a) != 11)
        {
            printf("test_sum_num error\n");
            return 0;
        }
    }

    {
        int a = -23123;

        if (sum_num(a) != 11)
        {
            printf("test_sum_num error\n");
            return 0;
        }
    }
    return 1;
}


int test_luck_ticket()
{
    {
        if (luck_ticket() != 55252)
        {
            printf("test_luck_ticket error\n");
            return 0;
        }
    }
    return 1;
}


int test_parenthesis_rule()
{
    {
        char *str = "[][123][[]]";
        if (parenthesis_rule(str) != 1)
        {
            printf("test_parenthesis_rule error\n");
            return 0;
        }
    }

    {
        char *str = "(()())(())";
        if (parenthesis_rule(str) != 1)
        {
            printf("test_parenthesis_rule error\n");
            return 0;
        }
    }

    {
        char *str = "{}";
        if (parenthesis_rule(str) != 1)
        {
            printf("test_parenthesis_rule error\n");
            return 0;
        }
    }

    {
        char *str = "}{{}}";
        if (parenthesis_rule(str) != 0)
        {
            printf("test_parenthesis_rule error\n");
            return 0;
        }
    }

    {
        char *str = ")(";
        if (parenthesis_rule(str) != 0)
        {
            printf("test_parenthesis_rule error\n");
            return 0;
        }
    }

    {
        char *str = "[][]]]";
        if (parenthesis_rule(str) != 0)
        {
            printf("test_parenthesis_rule error\n");
            return 0;
        }
    }
    return 1;
}


int test_is_it_prime()
{
    {
        if (is_it_prime(17) != 1)
        {
            printf("test_is_it_prime error\n");
            return 0;
        }
    }

    {
        if (is_it_prime(4) != 0)
        {
            printf("test_is_it_prime error\n");
            return 0;
        }
    }

    {
        if (is_it_prime(1) != 0)
        {
            printf("test_is_it_prime error\n");
            return 0;
        }
    }
    return 1;
}


int test_str_in_str()
{
    {
        char *str1 = "1234567899";
        char *str2 = "99";
        if (str_in_str(str2, str1) != 1)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }

    {
        char *str1 = "1234567899";
        char *str2 = "9";
        if (str_in_str(str2, str1) != 2)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }

    {
        char *str1 = "1234567899";
        char *str2 = "5";
        if (str_in_str(str2, str1) != 1)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }

    {
        char *str1 = "1111";
        char *str2 = "11";
        if (str_in_str(str2, str1) != 3)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }

    {
        char *str1 = "1111";
        char *str2 = "2";
        if (str_in_str(str2, str1) != 0)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }

    {
        char *str1 = "1111";
        char *str2 = "111111111111";
        if (str_in_str(str2, str1) != 0)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }

    {
        char *str1 = "1";
        char *str2 = "1";
        if (str_in_str(str2, str1) != 1)
        {
            printf("test_str_in_str error\n");
            return 0;
        }
    }
    return 1;
}


int test_swap_value_or()
{
    {
        int a = 10, b = -10;
        int test_a = a, test_b = b;

        swap_value_or(&a, &b);

        if (a != test_b || b != test_a)
        {
            printf("test_swap_value_or error\n");
            return 0;
        }
    }

    return 1;
}


int test_array_reverse()
{
    {
        int mas1[3] = {-1, 2, 3};
        int mas2[3] = {3, 2, -1};

        array_reverse(mas1, 0, 3);

        if (!compare_array(mas1, mas2, 3))
        {
            printf("test_array_reverse error\n");
            return 0;
        }
    }

    {
        int mas1[3] = {-1, 2, 3};
        int mas2[3] = {2, -1, 3};

        array_reverse(mas1, 0, 2);
        if (!compare_array(mas1, mas2, 3))
        {
            printf("test_array_zero error\n");
            return 0;
        }
    }

    {
        int mas1[3] = {-1, 2, 3};
        int mas2[3] = {2, -1, 3};

        array_reverse(mas1, 0, 3);
        if (compare_array(mas1, mas2, 3))
        {
            printf("test_array_zero error\n");
            return 0;
        }
    }

    return 1;
}

void test_all()
{
    test_swap_value();

    test_array_zero();

    test_remainder1();

    test_sum_num();

    test_luck_ticket();

    test_parenthesis_rule();

    test_is_it_prime();

    test_str_in_str();

    test_swap_value_or();

    test_array_reverse();
}

int main()
{

    test_all();

    return 0;
}
