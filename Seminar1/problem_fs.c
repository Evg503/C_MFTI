#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long number;

void print_num(number n, number b, number i) {
    number digit = n % i;
    n /= i;
    if (n) {
        print_num(n, b*i, i+1);
    }
    printf("%llu.", digit);
}

int main() {
    number x = 0;
    int res;

    res = scanf("%llu", &x);
    assert(res == 1);
    print_num(x, 1llu, 2llu);
}
