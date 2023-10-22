#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int num;


int main() {
    num n = 0, b=0;
    unsigned char *arr;
    int res;

    res = scanf("%d", &n);
    assert(res == 1);
    arr = malloc(n * 1);

    for (int i = 0; i < n; ++i) {
        int byte;
        res = scanf("%d", &byte);
        assert(res == 1);
        assert(0 <= byte && byte <= 255);
        arr[i] = byte;
    }
    res = scanf("%d", &b);
    assert(res == 1);

    if(b<8*n){
        int idx = b>>3;
        int bit = b&7;
        arr[idx] ^= 1<<bit;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
