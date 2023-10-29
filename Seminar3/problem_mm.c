#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
    int n;
    int *a;

    int res;

    res = scanf("%d", &n);
    assert(res == 1);

    if (n <= 0) {
        printf("0 0\n");
        return 0;
    }
    a = calloc(n, sizeof(int));
    assert(a != NULL);


    for (int i = 0; i < n; ++i) {
        res = scanf("%d", a + i);
        assert(res == 1);
    }

    {
        int min = a[0];
        int max = a[0];
        for (int i = 1; i < n; ++i) {
            if (min > a[i]) min = a[i];
            if (max < a[i]) max = a[i];
        }

        printf("%d %d\n", min, max);
    }
    free(a);
}