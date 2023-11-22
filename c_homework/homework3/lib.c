#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define size    10

void fill_mas_rand(int*mas, int len, int limit)
{
    srand(clock());
    if (limit)
    {
        limit++;
        for (int i = 0; i < len; i++)
        {
            *(mas + i) = rand() % (limit);
        }
    }
    else{
        limit++;
        for (int i = 0; i < len; i++)
        {
            *(mas + i) = rand();
        }
    }
}


void swap_value_or(int *number1, int *number2)
{
    if (number1!=number2)
    {
        *number1 ^= *number2;
        *number2 ^= *number1;
        *number1 ^= *number2;
    }
}


void insertion_sort(int *mas, int len_mas)
{
    for (int i = 1; i < len_mas; ++i)
    {
        for (int j = i; j>0;--j)
        {
            if (*(mas + j) < *(mas + j - 1))
            {
                swap_value_or(mas+j, mas + j - 1);
            }
        }
    }
}


void q_sort(int *mas, int len)
{
    if (len>9) //Оптимальное значение тут 3
    {
        int *main_i, *start = mas, *end = mas + len - 1;
        if (*mas >= *(mas + len - 1) && *mas <= *(mas + len/2) || *mas <= *(mas + len - 1) && *mas >= *(mas + len/2) )
        {
            main_i = mas;
        }
        else if (*(mas + len - 1) >= *mas && *(mas + len - 1) <= *(mas + len/2) || *(mas + len - 1) <= *mas && *(mas + len - 1) >= *(mas + len/2))
        {
            main_i = (mas + len -1);
        }
        else
        {
            main_i = (mas + len/2);
        }
        while(1)
        {
            while (*(start) <= *(main_i) && start <= mas + len - 1)
            {
                ++start;
                if (start > end)
                {
                    start--;
                    break;
                }
            }
            while (*(end) > *(main_i) && end >= mas)
            {
                --end;
            }
            if (start < end)
            {
                swap_value_or(start, end);
                if(main_i == end){
                    main_i = start;
                }
                else if (main_i == start)
                {
                    main_i = end;
                }
            }
            else
            {
                swap_value_or(end, main_i);
                main_i = end;
                break;
            }
        }
        int *main_help = main_i;
        int len_im = 0;
        for(; main_i > mas;main_i--, len_im++){ }
        q_sort(main_help + 1, len - len_im - 1);
        q_sort(mas, len_im);
    }
    else
    {
        insertion_sort(mas,len);
    }
}


int compare_array(int *mas1, int *mas2, int len)
{
    for (int i = 0; i < len; ++i){
        if (*(mas1 + i) != *(mas2 + i))return 0;
    }
    return 1;
}


int min(int a, int b)
{
    if (a>b)
    {
        return b;
    }
    return a;
}


char el_in_sort_mas(int *mas, size_t len_mas, int element)
{

    if ( len_mas < 4)
    {
        for (int i = 0; i < len_mas; ++i)
        {
            if (element == *(mas + i))
            {
                return 1;
            }
        }
        return 0;
    }
    if (element < *(mas + len_mas/2))
    {
        return el_in_sort_mas(mas, len_mas/2, element);
    }
    return el_in_sort_mas(mas + len_mas/2, len_mas - len_mas/2, element);
}


void *selection_sort(int * mas, int len, char if1down)
{
    int lower_i;
    if (!if1down)
    {
        for (int i = 0; i <= len - 2; i++)
        {
            lower_i = i;
            for (int g = i + 1; g < len; g++)
            {
                if (*(mas + g) < *(mas + lower_i)) lower_i = g;
            }
            if (lower_i != i)
            {
                swap_value_or((mas + i), (mas + lower_i));
            }
        }
    }
    else{
        for (int i = 0; i <= len - 2; i++)
        {
            lower_i = i;
            for (int g = i + 1; g < len; g++)
            {
                if (*(mas + g) > *(mas + lower_i)) lower_i = g;
            }
            if (lower_i != i)
            {
                swap_value_or((mas + i), (mas + lower_i));
            }
        }
    }
}


int matching_elements(int *masn, size_t len_masn,
                      int *mask, size_t len_mask,
                      int *mas_new, int len_mas_new)
{
    q_sort(masn, len_masn);
    int k = 0, new = 0;
    while(1)
    {
        while (k<len_mask)
        {
            if(el_in_sort_mas(masn, len_masn, *(mask + k)))
            {
                *(mas_new + new) = *(mask + k);
                new++;
                if (new == len_mas_new)
                {
                    return new;
                }
            }
            k++;
        }
        if (!new)
        {
            return new;
        }
        return new;
    }
}


int more_meet_el(int *mas, size_t len_mas)
{
    if (len_mas == 1)
    {
        return *mas;
    }
    int *help_mas = malloc(len_mas*sizeof(int));
    for (int i = 0; i < len_mas; ++i)
    {
        help_mas[i] = mas[i];
    }
    q_sort(help_mas, len_mas);
    int kolv_el_max = 1, kolv_el_now = 1, ind_max_el = 0;
    for (int i = 1; i < len_mas; ++i)
    {
        if (*(help_mas+i)==*(help_mas+i-1))
        {
            kolv_el_now++;
            ind_max_el = kolv_el_max>=kolv_el_now?ind_max_el:i-1;
            kolv_el_max = kolv_el_max>=kolv_el_now?kolv_el_max:kolv_el_now;
        }
        else
        {
            kolv_el_now =1;
        }
    }
    int g = *(help_mas + ind_max_el);
    free(help_mas);
    return g;
}


void print_array(int *mas, int length)
{
    printf("{");
    for (int i = 0; i<length; i++)
    {
        printf("%d, ", mas[i]);
    }
    printf("\b\b}\n");
}