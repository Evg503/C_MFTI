#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long number;

number fib_m(number n, number m) {
    number old =0;
    number curr = 1;
    if(n<2) {
        return n;
    }
    for(number i = 1; i<n;++i)
    {
        number next = (old+curr)%m;
        old = curr;
        curr = next;
    }
    return curr;
}

int main() {
    number x = 0, m = 0, answer = 0;
    int res;

    res = scanf("%llu%llu", &x, &m);
    assert(res == 2);
    answer = fib_m(x, m);

    printf("%lld", answer);
}
