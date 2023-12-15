#include <stdio.h>


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