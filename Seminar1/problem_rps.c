#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int number;

number pwr(number x, number n, number m) {
    number out = 1;
    printf("%d ^ %d mod %d = ",x, n, m);
    while (n > 0) {
        if (n % 2 == 1) {
            out = (out * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    printf("%d\n", out);
    return out;
}

number spow_mod(number x, number n, number m) {
    number out = 1;
    printf("(%d ^^ %d mod %d = ...\n",x, n, m);
    while (n > 0) {
        if (n % 2 == 1) {
            out = pwr(out, x, m);
        }
        x = pwr(x, x, m);
        n /= 2;
    }
    printf("...^^ = %d\n", out);
    return out;
}


void test()
{
    assert(spow_mod(2, 1, 10)  == 2);
    assert(spow_mod(2, 4, 10)  == 6);
}
int main() {
    number a, b, n, r;
    int res;
    test();
    return 0;
    res = scanf("%u%u%u", &a, &b, &n);
    assert(res == 3);
    r = spow_mod(a, b, n);
}
