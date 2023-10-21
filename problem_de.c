#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int number;

number extended_gcd(number x, number y, number *a, number *b) {
    number old_r = x, r = y, old_s, s, old_t, t;
    old_s = 1;
    s = 0;
    old_t = 0;
    t = 1;

    while (r != 0) {
        number q = old_r / r;
        number v = old_r - q * r;
        old_r = r;
        r = v;
        v = old_s - q * s;
        old_s = s;
        s = v;
        v = old_t - q * t;
        old_t = t;
        t = v;
    }
    if (old_r < 0) {
        old_r = -old_r;
        old_t = -old_t;
        old_s = -old_s;
    }
    if (a)
        *a = old_s;
    if (b)
        *b = old_t;
    return old_r;
}

int main() {
    number x = 0, y = 0, d, a, b, c;
    int res;

    res = scanf("%d%d%d", &a, &b, &c);
    assert(res == 3);
    d = extended_gcd(a, b, &x, &y);
    if (c % d != 0) {
        printf("NONE\n");
        return 0;
    }
    x *= c / d;
    y *= c / d;
    printf("%d %d\n", x, y);
}
