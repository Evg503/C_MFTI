#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long gcd(long long x, long long y) {
    long long q;
    x = llabs(x);
    y = llabs(y);
    if (y > x) {
        q = x;
        x = y;
        y = q;
    }
    do {
        q = x % y;
        x = y;
        y = q;
    } while (q != 0);
    return x;
}

int main() {
    long long x = 0, y = 0, g;
    int res;

    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%lld\n", g);
    return 0;
}
