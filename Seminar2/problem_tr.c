#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct point_t {
    int x, y;
};
struct triangle_t {
    struct point_t pts[3];
};

int double_area(struct triangle_t tr) {
    return abs(tr.pts[0].x * (tr.pts[1].y - tr.pts[2].y) +
           tr.pts[1].x * (tr.pts[2].y - tr.pts[0].y) +
           tr.pts[2].x * (tr.pts[0].y - tr.pts[1].y));
}

int main() {

    struct triangle_t t1 = {{{1, 1}, {2, 2}, {3, 3}}};
    struct triangle_t t2 = {{{-1, -1}, {2, -3}, {3, -2}}};

    printf("%d\n", double_area(t1));
    printf("%d\n", double_area(t2));

}

