#include <stdio.h>
#include <stdlib.h>

#include "lib.h"


int test_q_sort()
{
    {
        int mas1[10] = {0, 1,2,3,4,5,6,7,8,9};

        q_sort(mas1, 10);

        int mas2[10] = {0, 1,2,3,4,5,6,7,8,9};

        if (!compare_array(mas1, mas2, 10))
        {
            printf("test_q_sort error\n");
            return 0;
        }
    }

    {
        int mas1[10] = {7,1,0,5,4,2,9,8,3,6};

        q_sort(mas1, 10);

        int mas2[10] = {0, 1,2,3,4,5,6,7,8,9};

        if (!compare_array(mas1, mas2, 10))
        {
            printf("test_q_sort error\n");
            return 0;
        }
    }

    {
        int mas1[10] = {1, -1};

        q_sort(mas1, 2);

        int mas2[10] = {-1, 1};

        if (!compare_array(mas1, mas2, 2))
        {
            printf("test_q_sort error\n");
            return 0;
        }
    }

    return 1;
}


int test_matching_elements()
{
    {
        int mas1[10] = {0, 1,2,3,4,5,6,7,8,9};
        int mas2[9] = {0, 0, 1, 1, 0, 0, 1, -1, -1};

        int *mas3 = calloc(9, sizeof(int));
        matching_elements(mas1, 10, mas2, 9, mas3, 9);

        q_sort(mas3, 9);
        int mas_answer[9] = {0,0,0,0,0,0,1,1,1};

        if (!compare_array(mas3, mas_answer, 9))
        {
            printf("test_matching_elements error\n");
            free(mas3);
            return 0;
        }
        free(mas3);
    }

    {
        int mas1[10] = {7,1,0,5,4,2,9,8,3,6};

        int mas2[8] = {6,8,0,1,7,5,5,5};

        int *mas3 = calloc(8, sizeof(int));
        matching_elements(mas1, 10, mas2, 8, mas3, 8);

        q_sort(mas3, 8);
        int mas_answer[8] = {0,1,5,5,5,6,7,8};

        if (!compare_array(mas3, mas_answer, 7))
        {
            printf("test_matching_elements error\n");
            free(mas3);
            return 0;
        }
        free(mas3);
    }

    {
        int mas1[2] = {1, -1};

        int mas2[7] = {3,3,3,4,10,1000, -1000};

        int *mas3 = calloc(7, sizeof(int));
        matching_elements(mas1, 10, mas2, 7, mas3, 7);

        q_sort(mas3, 7);
        int mas_answer[7] = {0,0,0,0,0,0,0};

        if (!compare_array(mas3, mas_answer, 7))
        {
            printf("test_matching_elements error\n");
            free(mas3);
            return 0;
        }
        free(mas3);
    }

    return 1;
}


int test_more_meet_el()
{
    {
        int mas1[10] = {1, 0,2,3,4,5,6,7,8,9};

        int ans = more_meet_el(mas1, 10);

        if (ans != 0)
        {
            printf("test_matching_elements error\n");
            return 0;
        }
    }

    {
        int mas1[4] = {0,0,1,1};

        int ans = more_meet_el(mas1, 4);

        if (ans != 0)
        {
            printf("test_matching_elements error\n");
            return 0;
        }
    }

    {
        int mas1[4] = {1,1,0,0};

        int ans = more_meet_el(mas1, 4);

        if (ans != 0)
        {
            printf("test_matching_elements error\n");
            return 0;
        }
    }

    {
        int mas1[2] = {1111,1111};

        int ans = more_meet_el(mas1, 2);

        if (ans != 1111)
        {
            printf("test_matching_elements error\n");
            return 0;
        }
    }

    {
        int mas1[1] = {11};

        int ans = more_meet_el(mas1, 1);

        if (ans != 11)
        {
            printf("test_matching_elements error\n");
            return 0;
        }
    }

    return 1;
}


int main()
{
    test_q_sort();

    test_matching_elements();

    test_more_meet_el();

    return 0;
}
