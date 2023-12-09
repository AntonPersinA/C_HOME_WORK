//
// Created by anton on 09.12.2023.
//

#include <stdio.h>
#include "test.h"
#include "../stack.h"

int test_init()
{
    stack *st = stack_init(10);
    if (st->next != NULL || st->value != 10)
    {
        printf("error test_init\n");
        return 0;
    }
    return 1;
}

int test_add()
{
    stack *st = stack_init(10);
    st = stack_add(st, -10);
    if (st->next == NULL || st->value != -10)
    {
        printf("error test_add\n");
        return 0;
    }
    return 1;
}

int test_pop()
{
    stack *st = stack_init(10);
    st = stack_add(st, -10);
    char tteesstt = stack_pop(&st);
    if (st->next != NULL || st->value != 10 || tteesstt != -10)
    {
        printf("error test_pop\n");
        return 0;
    }
    return 1;
}