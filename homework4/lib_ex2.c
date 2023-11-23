//
// Created by anton on 23.11.2023.
//

#include <stdlib.h>
#include <stdio.h>

#include "lib_ex2.h"

int fill_file_input(int **mas)
{
    FILE *fr = fopen("test.txt", "r");

    int digit;
    int size = 1;

    int sq = fscanf(fr, "%d", &digit);
    while (sq != -1)
    {
        sq = fscanf(fr, "%d", &digit);
        size += 1;
    }
    fclose(fr);
    size--;

    *mas = calloc(size, sizeof(int));

    FILE *fr2 = fopen("test.txt", "r");

    for (int i = 0; i < size; ++i)
    {
        sq = fscanf(fr2, "%d", &digit);
        (*mas)[i] = digit;
    }

    fclose(fr2);
    return size;
}