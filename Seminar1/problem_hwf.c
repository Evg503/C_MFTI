#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 47

int fibs[N] = {0};
void fib_n(int n) {
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i < n; ++i) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
}

int next_turn(int total, int possible) {
    // TODO: ваш код здесь
    fib_n(N);
    if(possible>=total)
        return total;
    for (int i = N-1; i >=2 ;--i) {
        if(total>=fibs[i])
        {
            total-=fibs[i];
            if(total == 0 && fibs[i] <=possible)
                return fibs[i];
        }
    }
    return 1;
}

typedef int number;

void match(number total)
{
    number possible = total-1;
    printf("%d",total);
    while (total>0)
    {
        number step = next_turn(total,possible);
        possible = 2*step;
        total -= step;
        printf(".%d", step);
    }
    printf("!\n");
}
int main() {
    number x = 0;
    int res;
    res = scanf("%d", &x);
    assert(res == 1);
    assert(x>0);
    assert(x<INT_MAX);
    match(x);
}
