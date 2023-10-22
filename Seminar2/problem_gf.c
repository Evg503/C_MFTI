#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct sieve_t {
    int n;
    char *s;
};

typedef long long num;

void init_sieve(struct sieve_t *sv, int n);

void fill_sieve(struct sieve_t *sv);

int nth_prime(struct sieve_t *sv, int N);

int is_prime(struct sieve_t *sv, int N) {
    if (N < 2) return 0;
    assert(N < sv->n);
    return !sv->s[N];
}

int main() {

    struct sieve_t sieve;
    int N;
    int res;
    int count = 0, best_a = 0, best_b = 0;
    res = scanf("%d", &N);
    assert(res == 1);

    init_sieve(&sieve, 1000000);
    for (int a = -N+1; a < N; ++a) {
        for (int b = -N+1; b < N; ++b) {
            for (int n = 0; is_prime(&sieve, n * n + a * n + b); ++n) {
                if (count < n + 1) {
                    count = n + 1;
                    best_a = a;
                    best_b = b;
                }
            }
        }
    }

    printf("%d %d %d\n", best_a, best_b, count);

}

void init_sieve(struct sieve_t *sv, int n) {
    sv->n = n;
    sv->s = calloc(n, 1);
    fill_sieve(sv);
}

void fill_sieve(struct sieve_t *sv) {
    for (long long i = 2; i < sv->n; ++i) {
        if (sv->s[i] == 0) {
            for (long long j = i * i; j < sv->n; j += i) {
                sv->s[j] = 1;
            }
        }
    }
}

int nth_prime(struct sieve_t *sv, int N) {
    for (int i = 2; i < sv->n; ++i) {
        if (sv->s[i] == 0) {
            --N;
            if (N == 0) return i;
        }
    }
    return -1;
}
