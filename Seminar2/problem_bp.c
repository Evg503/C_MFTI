#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long num;


int main() {
    num n = 0;
    int res, a, b;

    res = scanf("%llu", &n);
    assert(res == 1);
    if (n == 0) {
        printf("-1\n");
        return 0;
    }

    a = b = 0;
    while ((n & 1) == 0) {
        ++a;
        n >>= 1;
    }
    b = a;
    while (n!=0){
        ++b;
        n>>=1;
    }
    --b;
    printf("%d %d\n", b, a);
    return 0;
}
