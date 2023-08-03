#include<stdio.h>
#include<math.h>

#define PIE 3.141592653589793238462643383 

int main() {
    int r;
    double s1, s2;
    scanf("%d", &r);
    r = double(r);
    s1 = r * r * PIE;
    s2 = r * r * 2;
    printf("%.6f\n%.6f\n", s1,s2);
    return 0;
}
