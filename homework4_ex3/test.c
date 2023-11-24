//
// Created by anton on 24.11.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test.h"
#include "ex3.h"

//#define CMakeList 0 // 1 or 0

void *add_phone_changed(int j, book *mas_book)
{
    FILE *fr;
    if (CMakeList)
    {
        fr = fopen("../C_HOME_WORK/homework4_ex3/test.txt", "r");
    }
    else
    {
        fr = fopen("test.txt", "r");
    }
    mas_book[j].name = calloc(101, sizeof(char));

    fgets(mas_book[j].name, 101, fr); // last byte for \0 !!!

    mas_book[j].number = calloc(21, sizeof(char));

    fgets(mas_book[j].number, 21, fr); // last byte for \0 !!!

    fclose(fr);
}


int test_add_phone()
{
    book *mas_book = calloc(1, sizeof(book));

    add_phone_changed(0, mas_book);

    if (strstr(mas_book[0].name, "anton") == NULL || strstr(mas_book[0].number, "8953") == NULL)
    {
        printf("error test_add_phone\n");
        free((mas_book[0].number));
        free((mas_book[0].name));
        free(mas_book);
        return 0;
    }
    free((mas_book[0].number));
    free((mas_book[0].name));
    free(mas_book);

    return 1;
}


int read_file_changed(int j, book *mas_book)
{
    FILE *fr;
    if (CMakeList)
    {
        fr = fopen("../C_HOME_WORK/homework4_ex3/test.txt", "r");
    }
    else
    {
        fr = fopen("test.txt", "r");
    }


    {
        while(1)
        {
            mas_book[j].name = calloc(101, sizeof(char));
            mas_book[j].number = calloc(21, sizeof(char));
            fgets(mas_book[j].name, 101, fr);
            if (strlen(mas_book[j].name) == 0)
            {
                free(mas_book[j].name);
                free(mas_book[j].number);
                fclose(fr);
                return j;
            }
            fgets(mas_book[j].number, 21, fr);
            if (strlen(mas_book[j].number) == 0)
            {
                free(mas_book[j].name);
                free(mas_book[j].number);
                fclose(fr);
                return j;
            }

            j += 1;
        }
    }
    fclose(fr);
}


int test_read_file()
{
    book *mas_book = calloc(3, sizeof(book));

    int j = read_file_changed(0, mas_book);

    if (strstr(mas_book[0].name, "anton") == NULL || strstr(mas_book[0].number, "8953") == NULL || j != 1)
    {
        printf("error test_add_phone\n");
        free((mas_book[0].number));
        free((mas_book[0].name));
        free(mas_book);
        return 0;
    }
    free((mas_book[0].number));
    free((mas_book[0].name));
    free(mas_book);
    return 1;
}


int test()
{

    if(!test_add_phone())
    {
        return 0;
    }
    if(!test_read_file())
    {
        return 0;
    }

    return 1;
}
