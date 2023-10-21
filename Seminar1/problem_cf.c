#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_chain(long long int x, long long int y);

long long gcd(long long x, long long y) {
    long long q;
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

int main() {
    long long x = 0, y = 0;
    int res;

    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    print_chain(x, y);
}

void print_chain(long long int x, long long int y) {

    long long d = x / y;
    long long r = x % y;
    printf("%lld ", d);
    if (r>0) {
        print_chain(y,r);
    }

}
