#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct mystruct1 {
    int x;
    int y;
    int r;
}Circle;

int Power(int base, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= base;
    }
    return result;
}

int main(){
    int TC;
    int distance;
    int dx, dy, dr, sr;
    int intersect;

    Circle C1, C2;

    bool cond;

    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d %d %d %d %d", &C1.x, &C1.y, &C1.r, &C2.x, &C2.y, &C2.r);
        dy = abs(C2.y - C1.y);
        dx = abs(C2.x - C1.x);
        dr = abs(C2.r - C1.r);
        dr = Power(dr, 2);
        sr = C2.r + C1.r;
        sr = Power(sr, 2);
        distance = Power(dy, 2) + Power(dx, 2);
        cond = (dx == 0) && (dy == 0) && (dr == 0);
        

        if (cond) {
            intersect = -1;
        }
        else if ((dr < distance) && (distance < sr)) {
            intersect = 2;
        }
        else if ((distance == dr) || (distance == sr)) {
            intersect = 1;
        }
        else {
            intersect = 0;
        }
        printf("%d\n", intersect);
    }
    return 0;
}