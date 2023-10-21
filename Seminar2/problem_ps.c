#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct sieve_t {
    int n;
    char *s;
};

typedef int num;

void fill_sieve(struct sieve_t *sv);

int nth_prime(struct sieve_t *sv, int N);


int main() {
    num n = 1000000;

    struct sieve_t sieve;
    sieve.n = n;
    sieve.s = calloc(n, 1);

    fill_sieve(&sieve);

    for (int i = 1; i < sieve.n; i += i) {
        int p = nth_prime(&sieve, i);
        printf("%d: %d\n", i, p);
    }
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
        if(sv->s[i] == 0 ){
            --N;
            if(N==0) return i;
        }
    }
    return -1;
}
