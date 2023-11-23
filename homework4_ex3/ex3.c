//
// Created by anton on 23.11.2023.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct telephone_book {
    char *number;
    char *name;
} book;


int print_phone(book *book2)
{
    printf("\tИмя: %s", book2->name);
    printf("\tНомер: %s", book2->number);
    return 1;
}


book *add_phone()
{
    printf("Введите имя\n");

    char *name = calloc(101, sizeof(char));

    fgets(name, 101, stdin); // last byte for \0 !!!

    book *book1 = calloc(1, sizeof(book));

    book1->name = name;

    printf("Введите nomer\n");

    char *number = calloc(21, sizeof(char));

    fgets(number, 21, stdin); // last byte for \0 !!!

    book1->number = number;

    return book1;
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
    printf("Введите цифру(6 для меню подсказок)\n");

    int case_init = 0;
    int i = 1;
    char *input = calloc(1000, sizeof(char));

    fgets(input, 1000, stdin);

    for (int j = (int)(strlen(input) - 2); j >= 0; --j)
    {
        if (('9' < input[j] || input[j] < '0'))
        {
            free(input);
            return start_work_prog(j, mas_book);
        }
        case_init += (int)(input[j] - '0') * i;
        i *= 10;
    }
    free(input);
    switch (case_init)
    {
        case 0:
        {
            printf("Выход осуществлен\n");
            return j;
        }

        case 1:
        {
            if (j > 99)
            {
                printf("Переполнение списка\n");
                return start_work_prog(j, mas_book);;
            }
            book *n1 = calloc(1, sizeof(book));
            if (n1 == NULL) {
                return start_work_prog(j, mas_book);
            }
            n1 = add_phone();
            mas_book[j] = *n1;
            free(n1);
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
            printf("Введите имя\n");

            char *name_search = calloc(101, sizeof(char));

            fgets(name_search, 101, stdin);

            for (int k = 0; k < j; ++k)
            {
                if ( strstr((mas_book[k].name), name_search)!= NULL && strstr(name_search, (mas_book[k].name))!= NULL)
                {
                    printf("Найден #%d:\n", k + 1);
                    print_phone(&(mas_book[k]));
                }
            }
            free(name_search);
            return start_work_prog(j, mas_book);
        }

        case 4:
        {
            printf("Введите номер\n");

            char *num_search = calloc(101, sizeof(char));

            fgets(num_search, 101, stdin);

            for (int k = 0; k < j; ++k)
            {
                if ( strstr((mas_book[k].number), num_search)!= NULL && strstr(num_search, (mas_book[k].number))!= NULL)
                {
                    printf("Найдено:\n");
                    print_phone(&(mas_book[k]));
                }
            }
            free(num_search);
            return start_work_prog(j, mas_book);
        }

        case 5:
        {
            FILE *fw = fopen("phone_book.txt", "w");
            for (int k = 0; k < j; ++k)
            {
                fprintf(fw, "Контакт: %s", ((mas_book[k]).name));
                fprintf(fw, "Номер: %s", ((mas_book[k]).number));
                fprintf(fw, "\n");
            }
            fclose(fw);
            return start_work_prog(j, mas_book);
        }
        case 6:
        {
            printf("0 - выйти\n1 - добавить запись (имя и телефон)\n2 - распечатать все имеющиеся записи\n3 - найти телефон по имени\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл\n");
            return start_work_prog(j, mas_book);
        }

        default:
        {
            return start_work_prog(j, mas_book);
        }
    }
}


int start_work()
{
    book *mas_book = calloc(100, sizeof(book));

    int i = start_work_prog(0, mas_book);

    printf("size = %ld\n", sizeof(book));

    for (int j = 1; j < i; ++j)
    {
        printf("SOOOOMMMEEETHING\n");
        free(mas_book[j].name);
        free(mas_book[j].number);
        free(&(mas_book[j]));
    }
    free(mas_book[0].name);
    free(mas_book[0].number);
    if(&(mas_book[0]) != mas_book)
    {
        free(&(mas_book[0]));
    }
    free(mas_book);


    return 1;
}

int main()
{
    start_work();


//    fclose(stdin);

    return 0;
}