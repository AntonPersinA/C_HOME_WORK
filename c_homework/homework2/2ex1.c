long long int fibonachi_def(int num)
{
    if (num <= 2)
    {
        return 1;
    }
    return fibonachi_def(num - 1) + fibonachi_def(num - 2);
}


long long int fibonachi_for(int n)
{
    long long num_1 = 1;
    long long num_2 = 1;
    long long helper = num_2;
    for (int i = 3; i <= n; i++)
    {
        helper = num_2;
        num_2 += num_1;
        num_1 = helper;
    }
    return num_2;
}