//
// Created by anton on 09.12.2023.
//
#pragma once

typedef struct stack
{
    char value;
    struct stack *next;
} stack;

stack* stack_init(char element);

stack* stack_add(stack* stack_ptr, char element);

void stack_print(stack* stack_ptr);

void stack_free(stack* stack_ptr);

char stack_pop(stack** stack_ptr);

int stack_len(stack* stack_ptr);