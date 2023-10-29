#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int *readArray(unsigned int n);

void printArray(const int *a, unsigned int n);

void shuffleArray(int *a, unsigned int n);

void inssort(int *arr, int len);

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

    if (n == 0) {
        printf("0\n");
        return 0;
    }
    a = readArray(n);
    shuffleArray(a, n);
    printArray(a, n);
    inssort(a, n);
    printArray(a, n);

}

int moveright(int *arr, int key, int last) {
    for (int i = last - 1; i >= 0; --i) {
        if (arr[i] > key)
            arr[i + 1] = arr[i];
        else
            return i + 1;
    }
    return 0;
}

void inssort(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        int key, pos;
        key = arr[i];
        pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}

void shuffleArray(int *a, unsigned int n) {
    for (int i = n; i > 1; --i) {
        int rnd = myrand() % i;
        int t = a[i - 1];
        a[i - 1] = a[rnd];
        a[rnd] = t;
    }
}

void printArray(const int *a, unsigned int n) {
    for (int i = 0; i < n; ++i) {
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
