#include <stdlib.h>
#include "stdio.h"

#include "stack.h"

int main()
{
    stack *st = stack_init(10);
    st = stack_add(st, 20);

    printf("pop = %d\n", stack_pop(&st));

    stack_free(st);
    return 0;
}