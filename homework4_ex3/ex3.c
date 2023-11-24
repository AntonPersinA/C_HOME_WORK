//
// Created by anton on 23.11.2023.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex3.h"
#include "test.h"

#define size_num 21
#define size_name 101
#define size_input 200
#define size_mas_book 100


int print_phone(book *book2)
{
    printf("\tName: %s", book2->name);
    printf("\tPhone number: %s", book2->number);
    return 1;
}


void *add_phone(int j, book *mas_book)
{
    printf("Enter name\n");

    mas_book[j].name = calloc(size_name, sizeof(char));

    fgets(mas_book[j].name, size_name, stdin); // last byte for \0 !!!

    printf("Enter number\n");

    mas_book[j].number = calloc(size_num, sizeof(char));

    fgets(mas_book[j].number, size_num, stdin); // last byte for \0 !!!

}


int print_allbook(int j, book *mas_book)
{
    printf("-----------------------------------\n");
    for (int i = 0; i < j; ++i)
    {
        printf("%d)\n", i + 1);
        print_phone(&(mas_book[i]));
    }
    printf("-----------------------------------\n");
}


int add_to_file(book *book1)
{
    return 0;
}

int start_work_prog(int j, book *mas_book)
{
    printf("Enter a number:\n0 - Exit\n1 - Add a note (name and phone number)\n2 - print all existing records\n3 - find phone by name\n4 - find a name by phone\n5 - save current data to file\n6 - help\n");

    int case_init = 0;
    int i = 1;
    char *input = calloc(size_input, sizeof(char));

    fgets(input, size_input, stdin);

    for (int jj = (int)(strlen(input) - 2); jj >= 0; --jj)
    {
        if (('9' < input[jj] || input[jj] < '0'))
        {
            free(input);
            return start_work_prog(j, mas_book);
        }
        case_init += (int)(input[jj] - '0') * i;
        i *= 10;
    }
    free(input);
    switch (case_init)
    {
        case 0:
        {
            printf("Exit completed\n");
            return j;
        }

        case 1:
        {
            if (j > size_mas_book - 1)
            {
                printf("List overflow\n");
                return start_work_prog(j, mas_book);;
            }
            add_phone(j, mas_book);
            j += 1;

            return start_work_prog(j, mas_book);
        }

        case 2:
        {
            print_allbook(j, mas_book);
            return start_work_prog(j, mas_book);
        }

        case 3:
        {
            printf("Enter name\n");

            char *name_search = calloc(size_name, sizeof(char));

            fgets(name_search, size_name, stdin);

            for (int k = 0; k < j; ++k)
            {
                if ( strstr((mas_book[k].name), name_search)!= NULL && strstr(name_search, (mas_book[k].name))!= NULL)
                {
                    printf("Found #%d:\n", k + 1);
                    print_phone(&(mas_book[k]));
                }
            }
            free(name_search);
            return start_work_prog(j, mas_book);
        }

        case 4:
        {
            printf("Enter number\n");

            char *num_search = calloc(size_num, sizeof(char));

            fgets(num_search, size_num, stdin);

            for (int k = 0; k < j; ++k)
            {
                if ( strstr((mas_book[k].number), num_search)!= NULL && strstr(num_search, (mas_book[k].number))!= NULL)
                {
                    printf("Found:\n");
                    print_phone(&(mas_book[k]));
                }
            }
            free(num_search);
            return start_work_prog(j, mas_book);
        }

        case 5:
        {
            FILE *fw;
            if (CMakeList)
            {
                fw = fopen("../C_HOME_WORK/homework4_ex3/phone_book.txt", "w");
            }
            else
            {
                fw = fopen("phone_book.txt", "w");
            }

            if (fw == NULL)
            {
                printf("file open error\n");
                return j;
            }
            for (int k = 0; k < j; ++k)
            {
                fprintf(fw, "%s", ((mas_book[k]).name));
                fprintf(fw, "%s", ((mas_book[k]).number));
            }
            fclose(fw);
            return start_work_prog(j, mas_book);
        }
        case 6:
        {
            printf("Enter a number:\n0 - Exit\n1 - Add a note (name and phone number)\n2 - print all existing records\n3 - find phone by name\n4 - find a name by phone\n5 - save current data to file\n6 - help\n");
            return start_work_prog(j, mas_book);
        }

        default:
        {
            return start_work_prog(j, mas_book);
        }
    }
}


int read_file(int j, book *mas_book)
{
    FILE *fr;
    if (CMakeList)
    {
        fr = fopen("../C_HOME_WORK/homework4_ex3/phone_book.txt", "r");

    }
    else
    {
        fr = fopen("phone_book.txt", "r");
    }

    {
        while(1)
        {
            mas_book[j].name = calloc(size_name, sizeof(char));
            mas_book[j].number = calloc(size_num, sizeof(char));
            fgets(mas_book[j].name, size_name, fr);
            if (strlen(mas_book[j].name) == 0)
            {
                free(mas_book[j].name);
                free(mas_book[j].number);
                fclose(fr);
                return j;
            }
            fgets(mas_book[j].number, size_num, fr);
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


int start_work()
{
    book *mas_book = calloc(size_mas_book, sizeof(book));

    int count_readline = 0;
    count_readline = read_file(0, mas_book);

    int i = start_work_prog(count_readline, mas_book);

    for (int j = 0; j < i; ++j)
    {
        free(mas_book[j].name);
        free(mas_book[j].number);
    }
    free(mas_book);

    return 1;
}

int main()
{
    if(test())
    {
        start_work();
    }

    return 0;
}