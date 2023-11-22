#include <stdio.h>


long long ll_pow_n(int m, int n){
    long long ans = 1;
    for(int i = 0; i<n;++i)
        ans*=m;
    return ans;
}


long long ll_pow_logn(int m, int n){
    long long otv = 1;
    if (n == 0){return 1;}
    while (n>1){
        if (n%2 == 0){
            m*=m;
            n>>=1;
        }
        else{
            otv*=m;
            n-=1;
            m*=m;
            n>>=1;
        }
    }
    return otv*m;
}