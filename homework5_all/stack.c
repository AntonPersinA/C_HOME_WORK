#include <stdlib.h>
#include "stdio.h"

#include "stack.h"

stack* stack_init(char element)
{
    stack *result = calloc(1, sizeof(stack));
    result->next = NULL;
    result->value = element;

    return result;
}

stack* stack_add(stack* stack_ptr, char element)
{
    stack *result = calloc(1, sizeof(stack));
    result->next = stack_ptr;
    result->value = element;

    return result;
}

void stack_print(stack* stack_ptr) {
    if (stack_ptr->next == NULL) {
        printf("%d\n", stack_ptr->value);
        return;
    }
    printf("%d\n", stack_ptr->value);
    stack_print(stack_ptr->next);
}


void stack_free(stack* stack_ptr)
{
    if (stack_ptr->next == NULL)
    {
        free(stack_ptr);
        return;
    }
    stack_free(stack_ptr->next);
    free(stack_ptr);
}


char stack_pop(stack** stack_ptr)
{
    if ((*stack_ptr)->next == NULL)
    {
        char res = (*stack_ptr)->value;
        free(*stack_ptr);
        return res;
    }
    stack* ptr = *stack_ptr;
    *stack_ptr = (*stack_ptr)->next;
    char res = ptr->value;
    free(ptr);
    return res;
}