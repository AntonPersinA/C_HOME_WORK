#include <stddef.h>

long long int fibonachi_def(int n);

long long int fibonachi_for(int n);

long long int ll_pow_n(int m, int n);

long long int ll_pow_logn(int m, int n);

void print_array(int *mas, int length);

void swap_value_or(int *number1, int *number2);

//Заполняет массив положительными числами меньших чем limit, limit = 0 снимает ограничение
void fill_mas_rand(int*mas, int len, int limit);

void *buble_sort(int *mas, int len, char if1down);

void counting_sort(int *mas, size_t len_mas);

int compare_array(int *mas1, int *mas2, int len);
