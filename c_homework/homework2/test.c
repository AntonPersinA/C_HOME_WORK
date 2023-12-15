#include <stdio.h>

#include "lib.h"

int test_fibonachi_def()
{
    {
        if (fibonachi_def(1) != 1)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    {
        if (fibonachi_def(2) != 1)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    {
        if (fibonachi_def(3) != 2)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    {
        if (fibonachi_def(4) != 3)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    {
        if (fibonachi_def(5) != 5)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    {
        if (fibonachi_def(6) != 8)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    {
        if (fibonachi_def(7) != 13)
        {
            printf("test_fibonachi_def error\n");
            return 0;
        }
    }

    return 1;
}


int test_fibonachi_for()
{
    {
        if (fibonachi_for(1) != 1)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }
    {
        if (fibonachi_for(2) != 1)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }

    {
        if (fibonachi_for(3) != 2)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }

    {
        if (fibonachi_for(4) != 3)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }

    {
        if (fibonachi_for(5) != 5)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }

    {
        if (fibonachi_for(6) != 8)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }

    {
        if (fibonachi_for(7) != 13)
        {
            printf("test_fibonachi_for error\n");
            return 0;
        }
    }

    return 1;
}

int test_ll_pow_n()
{
    {
        int m = 2, n = 2;

        if (ll_pow_n(m, n) != 4)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    {
        int m = 2, n = 3;

        if (ll_pow_n(m, n) != 8)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    {
        int m = 0, n = 0;

        if (ll_pow_n(m, n) != 1)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    {
        int m = -10, n = 0;

        if (ll_pow_n(m, n) != 1)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    {
        int m = 10, n = 0;

        if (ll_pow_n(m, n) != 1)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    {
        int m = -3, n = 1;

        if (ll_pow_n(m, n) != -3)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    {
        int m = -3, n = 2;

        if (ll_pow_n(m, n) != 9)
        {
            printf("test_ll_pow_n error\n");
            return 0;
        }
    }

    return 1;
}


int test_ll_pow_logn()
{
    {
        int m = 2, n = 2;

        if (ll_pow_logn(m, n) != 4)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = 2, n = 3;

        if (ll_pow_logn(m, n) != 8)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = 0, n = 0;

        if (ll_pow_logn(m, n) != 1)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = -10, n = 0;

        if (ll_pow_logn(m, n) != 1)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = 10, n = 0;

        if (ll_pow_logn(m, n) != 1)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = -3, n = 1;

        if (ll_pow_logn(m, n) != -3)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = -3, n = 2;

        if (ll_pow_logn(m, n) != 9)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = -3, n = 3;

        if (ll_pow_logn(m, n) != -27)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    {
        int m = -3, n = 4;

        if (ll_pow_logn(m, n) != 81)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }


    {
        int m = -3, n = 5;

        if (ll_pow_logn(m, n) != -243)
        {
            printf("ll_pow_logn error\n");
            return 0;
        }
    }

    return 1;
}


int test_buble_sort()
{
    {
        int mas1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        buble_sort(mas1, 10, 0);

        int mas2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        if (!compare_array(mas1, mas2, 10))
        {
            printf("test_buble_sort error\n");
            return 0;
        }
    }

    {
        int mas1[10] = {7, 1, 0, 5, 4, 2, 9, 8, 3, 6};

        buble_sort(mas1, 10, 0);

        int mas2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        if (!compare_array(mas1, mas2, 10))
        {
            printf("test_buble_sort error\n");
            return 0;
        }
    }

    {
        int mas1[10] = {1, -1};

        buble_sort(mas1, 2, 0);

        int mas2[10] = {-1, 1};

        if (!compare_array(mas1, mas2, 2))
        {
            printf("test_buble_sort error\n");
            return 0;
        }
    }

    printf("time buble sort work 100`000 element = 18.5\n");
    return 1;
}


int test_counting_sort()
{
    {
        int mas1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        counting_sort(mas1, 10);

        int mas2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        if (!compare_array(mas1, mas2, 10))
        {
            printf("test_counting_sort error\n");
            return 0;
        }
    }

    {
        int mas1[10] = {7, 1, 0, 5, 4, 2, 9, 8, 3, 6};

        counting_sort(mas1, 10);

        int mas2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        if (!compare_array(mas1, mas2, 10))
        {
            printf("test_counting_sort error\n");
            return 0;
        }
    }

    {
        int mas1[10] = {1, -1};

        counting_sort(mas1, 2);

        int mas2[10] = {-1, 1};

        if (!compare_array(mas1, mas2, 2))
        {
            printf("test_counting_sort error\n");
            return 0;
        }
    }

    printf("time counting sort work 100`000 element = 0.002198\n");
    return 1;
}


void test_all()
{
    test_fibonachi_def();

    test_fibonachi_for();

    test_ll_pow_n();

    test_ll_pow_logn();

    test_buble_sort();

    test_counting_sort();
}


int main()
{
    test_all();

    return 0;
}
