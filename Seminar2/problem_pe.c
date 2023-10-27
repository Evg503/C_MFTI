#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct sieve_t {
    int n;
    unsigned char *s;
};

typedef int num;

void fill_sieve(struct sieve_t *sv);

int nth_prime(struct sieve_t *sv, int  N);

int is_bit(struct sieve_t *sv, int n) {
    if (n >= 8 * sv->n) return 0;
    return (sv->s[n >> 3] & (1 << (n & 7))) != 0;
}

void set_bit(struct sieve_t *sv, int n) {
    assert(n < 8 * sv->n);
    sv->s[n >> 3] |= (1 << (n & 7));
}

void fill_sieve(struct sieve_t *sv) {
    set_bit(sv, 0);
    set_bit(sv, 1);
    for (long long i = 2; i < 8 * sv->n; ++i) {
        if (!is_bit(sv, i)) {
            for (long long j = i * i; j < 8 * sv->n; j += i) {
                set_bit(sv, j);
            }
        }
    }
}

int is_prime(struct sieve_t *sv, unsigned n)
{
    return !is_bit(sv, n);
}

int nth_prime(struct sieve_t *sv, int N) {
    for (int i = 2; i < 8 * sv->n; ++i) {
        if (!is_bit(sv, i)) {
            --N;
            if (N == 0) return i;
        }
    }
    return -1;
}

int main() {
    num n = 1000000;

    struct sieve_t sieve;
    sieve.n = n;
    sieve.s = calloc(n, 1);

    fill_sieve(&sieve);
    printf("Sieve filled\n");
    for(int i = 0; i<20;++i){
        printf("%02x",sieve.s[i]);
    }
    printf("\n");
    for(int i = 0; i<20;++i){
        printf("%01x",is_prime(&sieve, i));
    }

    for (int i = 1; i < sieve.n; i += i) {
        int p = nth_prime(&sieve, i);
        printf("%d: %d\n", i, p);
    }

}

