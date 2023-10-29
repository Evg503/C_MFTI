#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int myrand() {
    static unsigned long int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (unsigned int) (seed / 65536) % 32768;
}

int main() {
    unsigned n;
    int *a;

    int res;

    res = scanf("%u", &n);
    assert(res == 1);

    if(n == 0)
    {
        printf("0\n");
        return 0;
    }
    a = calloc(n, sizeof(int));
    assert(a != NULL);

    for (int i = 0; i < n; ++i) {
        res = scanf("%d", a + i);
        assert(res == 1);
    }

    for (int i = n; i > 1; --i) {
        int rnd = myrand() % i;
        int t = a[i-1];
        a[i-1] = a[rnd];
        a[rnd] = t;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

}