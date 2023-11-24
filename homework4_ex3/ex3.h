//
// Created by anton on 24.11.2023.
//

#ifndef UNTITLED1_EX3_H
#define UNTITLED1_EX3_H

typedef struct telephone_book {
    char *number;
    char *name;
} book;

#define CMakeList 0 // 1 or 0

int print_phone(book *book2);

void *add_phone(int j, book *mas_book);

int print_allbook(int j, book *mas_book);

int start_work_prog(int j, book *mas_book);

int read_file(int j, book *mas_book);

int start_work();

#endif //UNTITLED1_EX3_H
