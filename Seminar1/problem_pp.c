#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long number;

number fib_m(number n, number m) {
    number old = 0;
    number curr = 1;
    if (n < 2) {
        return n;
    }
    for (number i = 1; i < n; ++i) {
        number next = (old + curr) % m;
        old = curr;
        curr = next;
    }
    return curr;
}

number piz(number m) {
    number old = 0, curr = 1;
    if (m < 2)
        return m;
    for (number i = 1;; ++i) {
        number next = (old + curr) % m;
        old = curr;
        curr = next;
        if (old == 0 && curr == 1)
            return i;
    }

}

void test() {
    assert(piz(0) == 0);
    assert(piz(1) == 1);
    assert(piz(10) == 60);
}

int main() {
    number x = 0, m = 0, answer = 0, pz;
    int res;
    //test();
    res = scanf("%llu%llu", &x, &m);
    assert(res == 2);
    pz = piz(m);
    answer = fib_m(x % pz, m);

    printf("%lld %lld", answer, pz);
}
