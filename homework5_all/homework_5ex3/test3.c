//
// Created by anton on 10.12.2023.
//

#include <stdio.h>
#include "test3.h"
#include "../stack.h"

int test_init()
{
    stack *st = stack_init(10);
    if (st->next != NULL || st->value != 10)
    {
        printf("error test_init\n");
        stack_free(st);
        return 0;
    }
    stack_free(st);
    return 1;
}

int test_add()
{
    stack *st = stack_init(10);
    st = stack_add(st, -10);
    if (st->next == NULL || st->value != -10)
    {
        printf("error test_add\n");
        stack_free(st);
        return 0;
    }
    stack_free(st);
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
        stack_free(st);
        return 0;
    }
    stack_free(st);
    return 1;
}

int test_len()
{
    {
        stack *st = stack_init(10);
        st = stack_add(st, -10);
        if (stack_len(st) != 2)
        {
            printf("error test_len\n");
            stack_free(st);
            return 0;
        }
        stack_free(st);
    }

    {
        stack *st = stack_init(10);
        if (stack_len(st) != 1)
        {
            printf("error test_len\n");
            stack_free(st);
            return 0;
        }
        stack_free(st);
    }
    return 1;
}
