#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef long long num;

num count_prime(num n);

void test() {
    for (int i = 1; i < 100; ++i) {
        printf("%d: %lld\n", i, count_prime(i));
    }
}

int main() {
    num n = 0, p;
    int res;

    res = scanf("%lld", &n);
    assert(res == 1);

    p = count_prime(n);

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

num count_prime(num n) {
    num *erath = calloc(n+1, sizeof(num));
    size_t end = 0;
    num p;

    for (num i = 2; i <= n; ++i) {
        erath[end++] = i;
        for (num j = 0; j < end-1; ++j) {
            if (i % erath[j] == 0) {
                --end;
                break;
            }
        }
    }
    p = end;
    free(erath);
    return p;
}
