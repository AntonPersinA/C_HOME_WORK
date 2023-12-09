//
// Created by anton on 09.12.2023.
//


#include <stdlib.h>
#include <stdio.h>

#include "../stack.h"
#include "test2.h"


stack* merge_scobe(stack *st)
{
    if (st->value == ')' && (st->next)->value == '(' && st->next != NULL)
    {
        char x = stack_pop(&st);
        char y = stack_pop(&st);
    }
    if (st->value == ']' && (st->next)->value == '[' && st->next != NULL)
    {
        char x = stack_pop(&st);
        char y = stack_pop(&st);
    }
    if (st->value == '}' && (st->next)->value == '{' && st->next != NULL)
    {
        char x = stack_pop(&st);
        char y = stack_pop(&st);
    }
    return st;
}


int patentness_rule()
{
    char *str = calloc(100, sizeof(char));
    char *read = fgets(str, 99, stdin);

    int i = 0;
    stack *st = stack_init(0);
    while (str[i] != '\0' && i < 100)
    {
        if (str[i] == '(')
        {
            st = stack_add(st, '(');
        }
        if (str[i] == ')')
        {
            st = stack_add(st, ')');
            st = merge_scobe(st);
        }
        if (str[i] == '{')
        {
            st = stack_add(st, '{');
        }
        if (str[i] == '}')
        {
            st = stack_add(st, '}');
            st = merge_scobe(st);
        }
        if (str[i] == '[')
        {
            st = stack_add(st, '[');
        }
        if (str[i] == ']')
        {
            st = stack_add(st, ']');
            st = merge_scobe(st);
        }
        ++i;
    }
    int res = stack_len(st) == 1;
    stack_free(st);
    free(str);
    return res;
}


int main()
{
    printf("return = %d\n", patentness_rule());

    test_init();
    test_add();
    test_len();
    test_pop();
    return 0;
}