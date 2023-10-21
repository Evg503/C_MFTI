#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long number;

number fibs[50];

void fib_n(number n) {
    fibs[0] = 0;
    fibs[1] = 1;
    for (number i = 2; i < n; ++i) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
}

void print_fib(number x)
{
    int idx = 49;
    while (fibs[idx] > x) --idx;
    for(;idx>1;--idx)
    {
        if(x>= fibs[idx]){
            x -= fibs[idx];
            printf("1");
        } else
        {
            printf("0");
        }
    }
}
/*20
 *     1 0 1 0 1 0
 * 21 13 8 5 3 2 1 1 0
 * */
int main() {
    number x = 0;
    int res;
    res = scanf("%lld", &x);
    assert(res == 1);
    assert(x>0);
    assert(x<INT_MAX);
    fib_n(50);
    print_fib(x);
}
