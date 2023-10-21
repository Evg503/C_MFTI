#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int number;

void print_num(number n, number b) {
    number digit = n % b;
    n /= b;
    if (n) {
        print_num(n, b);
    }
    printf("%d", digit);
}

int main() {
    number x = 0, y = 0;
    int res;

    res = scanf("%u%u", &x, &y);
    assert(res == 2);
    print_num(x, y);
}
