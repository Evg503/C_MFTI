#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long number;

struct m22 {
    number x00, x01, x10, x11;
};

struct m22 mult(struct m22 a, struct m22 b, number m) {
    struct m22 out;
    out.x00 = ((a.x00 * b.x00)%m + (a.x01 * b.x10)%m)%m;
    out.x01 = ((a.x00 * b.x01)%m + (a.x01 * b.x11)%m)%m;
    out.x10 = ((a.x10 * b.x00)%m + (a.x11 * b.x10)%m)%m;
    out.x11 = ((a.x10 * b.x01)%m + (a.x11 * b.x11)%m)%m;
    return out;
}

struct m22 pwr(struct m22 x, number n, number m) {
    struct m22 out = {1, 0, 0, 1};
    while (n > 0) {
        if (n % 2 == 1) {
            out = mult(out, x, m);
        }
        x = mult(x, x, m);
        n /= 2;
    }
    return out;
}

int main() {
    struct m22 x, out;
    number n = 0, m = 0;
    int res;
    res = scanf("%lld%lld%lld%lld%lld%lld", &x.x00, &x.x01, &x.x10, &x.x11, &n, &m);
    assert(res == 6);

    out = pwr(x, n, m);

    printf("%lld %lld %lld %lld\n", out.x00, out.x01, out.x10, out.x11);

}
