#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "q_sort.h"


void print_array(int *mas, int length)
{
    printf("{");
    for (int i = 0; i<length; i++)
    {
        printf("%d, ", mas[i]);
    }
    printf("\b\b}\n");
}


int fill_file_input(int **mas)
{
    FILE *fr = fopen("input.txt", "r");

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

    FILE *fr2 = fopen("input.txt", "r");

    for (int i = 0; i < size; ++i)
    {
        sq = fscanf(fr2, "%d", &digit);
        (*mas)[i] = digit;
    }

    fclose(fr2);
    return size;
}


int main()
{
    int *mas;

    int len = fill_file_input(&mas);

    q_sort(mas, len);

    free(mas);
    return 0;
}