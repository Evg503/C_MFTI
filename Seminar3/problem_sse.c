#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int *readArray(unsigned int n);

void printArray(const int *a, unsigned int n);

void sort_step(int *a, unsigned int n, unsigned int pos);

int main() {
    unsigned n, step;
    int *a;

    int res;

    res = scanf("%u", &n);
    assert(res == 1);
    a = readArray(n);
    res = scanf("%u", &step);
    assert(res == 1);
    sort_step(a, n, step);
    printArray(a, n);

    free(a);
}

void printArray(const int *a, unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int *readArray(unsigned int n) {
    int *a = calloc(n, sizeof(int));
    assert(a != NULL);

    for (int i = 0; i < n; ++i) {
        int res = scanf("%d", a + i);
        assert(res == 1);
    }
    return a;
}

void sort_step(int *a, unsigned int n, unsigned int pos) {
    unsigned int min = pos;
    for (unsigned int i = pos; i < n; ++i) {
        if (a[i] < a[min]) {
            min = i;
        }
    }
    if (pos != min) {
        int t = a[pos];
        a[pos] = a[min];
        a[min] = t;
    }

}
