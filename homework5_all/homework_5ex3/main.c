#include <stdlib.h>
#include <stdio.h>

#include "../stack.h"
#include "test3.h"


stack* scobe(stack *st, int* i, char *string)
{
    while (string[*i] != '\0' && (*i) < 100)
    {
        if (string[*i] == '(')
        {
            ++(*i);
            st = scobe(st, i, string);
        }
        if (string[*i] == ')')
        {
            return st;
        }
        if (string[*i] - '0' < 10 && string[*i] - '0' >= 0)
        {
            if (string[*i + 4] == '(')
            {
                st = stack_add(st, string[*i] - '0');
                int g = (*i);
                (*i) += 5;
                st = scobe(st, i, string);
                st = stack_add(st, string[g + 2] - '0');
            }
            else
            {
                st = stack_add(st, string[*i] - '0');
                while (string[*i + 4] - '0' < 10 && string[*i + 4] - '0' >= 0)
                {
                    st = stack_add(st, string[*i + 4] - '0');
                    st = stack_add(st, string[*i + 2] - '0');
                    (*i) += 4;
                }
                ++(*i);
            }
        }
    }
    return st;
}


stack* transform()
{
    char *str = calloc(100, sizeof(char));
    char *read = fgets(str, 99, stdin);

    int i = 0;
    stack *st = stack_init(0);
    while (str[i] != '\0' && i < 100)
    {
        if (str[i] == '(')
        {
            ++i;
            st = scobe(st, &i, str);

        }
        else
        {
            if (str[i] - '0' < 10 && str[i] - '0' >= 0)
            {
                if (str[i + 4] == '(')
                {
                    st = stack_add(st, str[i] - '0');
                    int g = (i);
                    (i) += 5;
                    st = scobe(st, &i, str);
                    st = stack_add(st, str[g + 2] - '0');
                }
                else
                {
                    st = stack_add(st, str[i] - '0');
                    while (str[i + 4] - '0' < 10 && str[i + 4] - '0' >= 0)
                    {
                        st = stack_add(st, str[i + 4] - '0');
                        st = stack_add(st, str[i + 2] - '0');
                        (i) += 4;
                    }
                    if (str[i + 4] == '(' && !(str[i + 2] - '0' < 10 && str[i + 2] - '0' >= 0))
                    {
                        char g = str[i + 2] - '0';
                        i += 4;
                        st = scobe(st, &i, str);
                        st = stack_add(st, g);
                    }
                }
            }

        }
        if (str[i] == ')' && i + 4 < 100 && (str[i + 4] - '0' < 10 && str[i + 4] - '0' >= 0))
        {
            while (str[i + 4] - '0' < 10 && str[i + 4] - '0' >= 0 && i + 4 < 100)
            {
                st = stack_add(st, str[i + 4] - '0');
                st = stack_add(st, str[i + 2] - '0');
                i += 4;
            }
        }
        ++i;
    }
    free(str);
    return st;
}


int main(int x, char **y)
{
    stack *fr = transform();
    stack_free(fr);

    test_init();
    test_add();
    test_len();
    test_pop();
    test_len();
    return 0;
}