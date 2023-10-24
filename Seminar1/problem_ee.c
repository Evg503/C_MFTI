#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long extended_gcd(long long x, long long y, long long *a, long long *b) {
    long long old_r = x, r = y, old_s, s, old_t, t;
    old_s = 1;
    s = 0;
    old_t = 0;
    t = 1;

    while (r != 0) {
        long long q = old_r / r;
        long long v = old_r - q * r;
        old_r = r;
        r = v;
        v = old_s - q * s;
        old_s = s;
        s = v;
        v = old_t - q * t;
        old_t = t;
        t = v;
    }
    if(old_r<0)
    {
        old_r = -old_r;
        old_t = -old_t;
        old_s = -old_s;
    }
    *a = old_s;
    *b = old_t;
    return old_r;
}

long long tests[][3] = {
        {2, 1, 1},
        {3,2,1},
        {2, 4, 2},
        {1769, 427, 61},
        {-1769, 427, 61},
        {1769, -427, 61},
        {-1769, -427, 61},
        {698917, -102089, 7853},
        {917, 872, 1},
        {-417143, -455947, 9701},
        {63862, -55298, 2},
        {702228, 373125, 3},
        {-659323, 727699,7},
        {1769, 551,29},
        {698917, -102089,7853},
        {0,0,0}
};
void test(){
    for (int i = 0; ; ++i) {
        long long x = tests[i][0];
        long long y = tests[i][1];
        long long exp = tests[i][2];
        long long a,b,d, d1;
        long long as,bs,ds;
        if(exp == 0) break;
        d = extended_gcd(x,y,&a,&b);
        ds = extended_gcd(y,x,&as,&bs);
        d1 = a*x+b*y;
        printf("testing %lld, %lld, %lld = %lld = %lld = %lld",x, y, exp, d, d1, ds);
        if(exp == d && d == d1)
            printf("...Ok\n");
        else
            printf("...ERROR\n");
    }
}

int main() {
    long long x, y, d, a, b;
    int res;
#if 0
    test();
    return 0;
#endif
    res = scanf("%lld%lld", &x, &y);
    assert(res == 2);
    d = extended_gcd(x, y, &a, &b);
    printf("%lld %lld %lld\n", a, b, d);
    return 0;
}
