#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long num;

num gcd(num x, num y) {
    num q;
    x = abs(x);
    y = abs(y);
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

num lcm(num a, num b) {
    return a * b / gcd(a, b);
}

int main() {
    num n = 0, l = 2;
    int res;

    res = scanf("%lld", &n);
    assert(res == 1);
    for (num i = 3; i <= n; ++i) {
        l = lcm(l, i);
    }
    printf("%lld\n", l);
    return 0;
}
