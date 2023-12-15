#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int fibonachi_def(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fibonachi_def(n - 1) + fibonachi_def(n - 2);
}


long long int fibonachi_for(int n)
{
    long long s_1 = 1;
    long long s_2 = 1;
    long long help;
    for (int i = 3; i <= n; i++)
    {
        help = s_2;
        s_2 += s_1;
        s_1 = help;
    }
    return s_2;
}

long long ll_pow_n(int num, int power)
{
    long long ans = 1;
    for (int i = 0; i < power; ++i)
    {
        ans *= num;
    }
    return ans;
}


long long ll_pow_logn(int num, int power)
{
    long long otv = 1;
    if (power == 0)
    {
        return 1;
    }
    while (power > 1)
    {
        if (power % 2 == 0)
        {
            num *= num;
            power >>= 1;
        } else
        {
            otv *= num;
            power -= 1;
            num *= num;
            power >>= 1;
        }
    }
    return otv * num;
}


void print_array(int *mas, int length)
{
    printf("{");
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", mas[i]);
    }
    printf("\b\b}\n");
}


void swap_value_or(int *number1, int *number2)
{
    if (number1 != number2)
    {
        *number1 ^= *number2;
        *number2 ^= *number1;
        *number1 ^= *number2;
    }
}


//Переменная limit ставит предел генерируемого значения, если стоит ноль, то limit определяется функцией rand()
void fill_mas_rand(int *mas, int len, int limit)
{
    srand(clock());
    if (limit)
    {
        limit++;
        for (int i = 0; i < len; i++)
            *(mas + i) = rand() % (limit);
    } else
    {
        for (int i = 0; i < len; i++)
        {
            *(mas + i) = rand();
        }
    }
}


//На массиве из 100'000 элементов рабоает 18.5/19.7/20.4 секунды
void *buble_sort(int *mas, int len, char if1down)
{
    if (if1down)
    {
        for (int i = len - 2; i >= 0; i--)
        {
            for (int g = i + 1; g < len; g++)
            {
                if (*(mas + g) >= (*(mas + g - 1)))
                {
                    swap_value_or((mas + g), (mas + g - 1));
                } else break;
            }
        }
    } else
    {
        for (int i = len - 2; i >= 0; i--)
        {
            for (int g = i + 1; g < len; g++)
            {
                if (*(mas + g) <= (*(mas + g - 1)))
                {
                    swap_value_or((mas + g), (mas + g - 1));
                } else break;
            }
        }
    }
}


void counting_sort_do_calculate(int max_el, size_t len_mas, int *mas)
{
    int *help_plus = calloc(max_el + 1, sizeof(int));
    if (help_plus == NULL)
    {
        printf("error malloc");
        return;
    }
    for (int i = 0; i < len_mas; ++i)
    {
        *(help_plus + *(mas + i)) += 1;
    }
    int mas_now = 0;
    for (int i = 0; i <= max_el; ++i)
    {
        for (int g = 0; g < *(help_plus + i); ++g)
        {
            *(mas + mas_now) = i;
            mas_now++;
        }
    }
    free(help_plus);
}


void counting_sort_do_sort(int *help_plus, int *help_minus, int max_el, int min_el, size_t len_mas, int *mas)
{
    for (int i = 0; i < len_mas; ++i)
    {
        if (*(mas + i) >= 0)
        {
            *(help_plus + *(mas + i)) += 1;
        } else
        {
            *(help_minus - *(mas + i)) += 1;
        }
    }
    int mas_now = 0;
    for (int i = -min_el; i >= 1; --i)
    {
        for (int g = 0; g < *(help_minus + i); ++g)
        {
            *(mas + mas_now) = -i;
            mas_now++;
        }
    }
    for (int i = 0; i <= max_el; ++i)
    {
        for (int g = 0; g < *(help_plus + i); ++g)
        {
            *(mas + mas_now) = i;
            mas_now++;
        }
    }
    free(help_plus);
    free(help_minus);
}

//На массиве из 100'000 элементов при лимите значений равным 100 рабоает 0.002198/0.008769, если лимит обозначен как максимум функции rand(), то секунд 6.038236/6.277364
void counting_sort(int *mas, size_t len_mas)
{
    int min_el = 0;
    int max_el = 0;
    for (int i = 0; i < len_mas; ++i)
    {
        if (*(mas + i) > max_el)max_el = *(mas + i);
        if (*(mas + i) < min_el)min_el = *(mas + i);
    }
    if (min_el >= 0)
    {
        counting_sort_do_calculate(max_el, len_mas, mas);
    } else
    {
        int *help_plus = calloc(max_el + 1, sizeof(int));
        int *help_minus = calloc(-min_el + 1, sizeof(int));
        if (help_plus == NULL)
        {
            printf("error help_plus malloc\n");
            return;
        }
        if (help_minus == NULL)
        {
            printf("error help_minus malloc\n");
            return;
        }
        counting_sort_do_sort(help_plus, help_minus, max_el, min_el, len_mas, mas);
    }
}


int compare_array(int *mas1, int *mas2, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (*(mas1 + i) != *(mas2 + i))
        {
            return 0;
        }
    }
    return 1;
}