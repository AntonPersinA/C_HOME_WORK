#include <stdio.h>
#include <stdlib.h>

#include "lib_ex2.h"

int test_fill_file_input()
{
    {
        int *mas;

        int len = fill_file_input(&mas);

        if (len != 3 ||
            mas[0] != -12 ||
            mas[1] != 1234 ||
            mas[2] != 12)
        {
            printf("error test_fill_file_input\n");
            free(mas);
            return 0;
        }
        free(mas);
    }
    return 1;
}


int main()
{
    test_fill_file_input();

    return 0;
}