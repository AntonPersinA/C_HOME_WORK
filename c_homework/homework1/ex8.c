#define size    10


void swap_value_or1(int *number1, int *number2) {
    if (number1!=number2) {
        *number1 ^= *number2;
        *number2 ^= *number1;
        *number1 ^= *number2;
    }
}


int *array_reverse1(int *mas, int a, int b){
    int help = 0;
    b--;
    for (a; a<b; a++) {
        if (a >= b-help){
            return mas;
        }
        swap_value_or1((mas + a), (mas + b - help));
        help+=1;
    }
    return mas;
}


int compare_array1(int *mas1, int *mas2, int len){
    for (int i = 0; i < len; ++i){
        if (*(mas1 + i) != *(mas2 + i))return 0;
    }
    return 1;
}