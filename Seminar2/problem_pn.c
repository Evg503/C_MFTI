#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef long long num;

num nth_prime(num n);

void test() {
    for (int i = 1; i < 100; ++i) {
        printf("%d: %lld\n", i, nth_prime(i));
    }
}

int main() {
    num n = 0, p;
    int res;

    res = scanf("%lld", &n);
    assert(res == 1);

    p = nth_prime(n);

    printf("%lld\n", p);

}

void
print_arr(num *arr, num end) {
    printf("Array:");
    for (int i = 0; i <end; ++i) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

num nth_prime(num n) {
    num *erath = calloc(n, sizeof(num));
    num end = 0;
    num p;

    for (num i = 2; end != n; ++i) {
        erath[end++] = i;
        for (num j = 0; j < end-1; ++j) {
            if (i % erath[j] == 0) {
                --end;
                break;
            }
        }
    }
    p = erath[n - 1];
    free(erath);
    return p;
}
