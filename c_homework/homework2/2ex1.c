long long int fibonachi_def(int n){
    if (n<=2)
        return 1;
    return fibonachi_def(n-1) + fibonachi_def(n-2);
}


long long int fibonachi_for(int n){
    long long s_1 = 1, s_2 = 1, help;
    for (int i = 3; i <= n; i++){
        help = s_2;
        s_2 += s_1;
        s_1 = help;
    }
    return s_2;
}