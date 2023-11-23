//
// Created by anton on 22.11.2023.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib_hw4.h"


int test_bin_str()
{
    {
        int a = 7;

        char *bin_a = bin_str(a);

//        printf("str = %s\n", bin_a);

        if (strlen(bin_a) != 4 ||
            bin_a[0] != '0' ||
            bin_a[1] != '1' ||
            bin_a[2] != '1'||
            bin_a[3] != '1')
        {
            printf("test_bin_str error\n");
            free(bin_a);
            return 0;
        }
        free(bin_a);
    }

    {
        int a = -7;

        char *bin_a = bin_str(a);

        if (strlen(bin_a) != 4 ||
            bin_a[0] != '1' ||
            bin_a[1] != '0' ||
            bin_a[2] != '0'||
            bin_a[3] != '1')
        {
            printf("test_bin_str error\n");
            free(bin_a);
            return 0;
        }
        free(bin_a);
    }

    {
        int a = 0;

        char *bin_a = bin_str(a);

        if (strlen(bin_a) != 1 ||
            bin_a[0] != '0')
        {
            printf("test_bin_str error\n");
            free(bin_a);
            return 0;
        }
        free(bin_a);
    }

    return 1;
}


int test_bin_to_10()
{
    {
        char *str_a = "1001";

        int a = bin_to_10(str_a);

        if (a != -7)
        {
            printf("test_bin_to_10 error\n");
            return 0;
        }
    }

    {
        char *str_a = "0111";

        int a = bin_to_10(str_a);

        if (a != 7)
        {
            printf("test_bin_to_10 error\n");
            return 0;
        }
    }

    {
        char *str_a = "0";

        int a = bin_to_10(str_a);

        if (a != 0)
        {
            printf("test_bin_to_10 error\n");
            return 0;
        }
    }

    return 1;
}


int test_bin_add()
{
    {
        char *str_a = "0111";
        char *str_b = "1001";

        char *str_c = bin_add(str_a, str_b);

        if (bin_to_10(str_c) != 0)
        {
            printf("test_bin_add error\n");
            free(str_c);
            return 0;
        }
        free(str_c);
    }

    return 1;
}


int main()
{
    test_bin_str();

    test_bin_to_10();

    test_bin_add();

    return 0;
}
