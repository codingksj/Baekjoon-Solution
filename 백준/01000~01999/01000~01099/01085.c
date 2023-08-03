#include<stdio.h>
#include<math.h>

int main() {
    int x, y, w, h;
    int min, min_x, min_y;
    scanf("%d %d %d %d", &x,&y,&w,&h);
    min_x = x < (w - x) ? x : (w - x);
    min_y = y < (h - y) ? y : (h - y);
    min = min_x < min_y ? min_x : min_y;
    printf("%d\n", min);
    return 0;
}
