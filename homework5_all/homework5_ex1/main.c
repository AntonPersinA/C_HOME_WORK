#include <stdlib.h>
#include "stdio.h"

#include "../stack.h"
#include "test.h"


stack* read_stdin()
{
    char *str = calloc(100, sizeof(char));
    char *read = fgets(str, 99, stdin);
    int i = 1;
    stack *res = stack_init(str[0]);
    while(str[i] != '\0' && i < 100)
    {
        res = stack_add(res, str[i]);
        ++i;
    }
    stack_pop(&res);
    return res;
}

char expression_equal()
{
    char *str = calloc(100, sizeof(char));
    char *read = fgets(str, 99, stdin);

    int i = 0;
    stack *st = stack_init(0);
    st = stack_add(st, 0);
    while (str[i] != '\0' && i < 100)
    {
        if (str[i] - '0' < 10 && str[i] - '0' >= 0)
        {
            st->value *= 10;
            st->value += str[i] - '0';
            if (i > 0)
            {
                if (str[i - 1] == '-')
                {
                    st->value *= -1;
                }
            }
            ++i;
            continue;
        }
        if (str[i] == ' ')
        {
            st = stack_add(st, 0);
            ++i;
            continue;
        }
        if (str[i] == '+')
        {
            if (i > 0)
            {
                if (str[i - 1] == ' ')
                {
                    stack_pop(&st);
                }
            }
            if (stack_len(st) < 3)
            {
                ++i;
                continue;
            }
            char x = stack_pop(&st);
            char y = stack_pop(&st);
            st = stack_add(st, x + y);
            ++i;
            continue;
        }
        if (str[i] == '-')
        {
            if (str[i + 1] - '0' < 10 && str[i + 1] - '0' >= 0)
            {
                ++i;
                continue;
            }
            if (i > 0)
            {
                if (str[i - 1] == ' ')
                {
                    stack_pop(&st);
                }
            }
            if (stack_len(st) < 3)
            {
                ++i;
                continue;
            }
            char x = stack_pop(&st);
            char y = stack_pop(&st);
            st = stack_add(st, y - x);
            ++i;
            continue;
        }
        if (str[i] == '*')
        {
            if (i > 0)
            {
                if (str[i - 1] == ' ')
                {
                    stack_pop(&st);
                }
            }
            if (stack_len(st) < 3)
            {
                ++i;
                continue;
            }
            char x = stack_pop(&st);
            char y = stack_pop(&st);
            st = stack_add(st, x * y);
            ++i;
            continue;
        }
        if (str[i] == '/')
        {
            if (i > 0)
            {
                if (str[i - 1] == ' ')
                {
                    stack_pop(&st);
                }
            }
            if (stack_len(st) < 3)
            {
                ++i;
                continue;
            }
            char x = stack_pop(&st);
            char y = stack_pop(&st);
            st = stack_add(st, y / x);
            ++i;
            continue;
        }
        ++i;
    }
    char res = st->value;
    stack_free(st);
    free(str);
    return res;
}

int main()
{
    printf("%d\n", expression_equal());
    return 0;
}