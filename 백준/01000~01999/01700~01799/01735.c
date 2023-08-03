#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}


int main() {
    int Z, M;
    int a, b;
    int c, d;
    int min;

    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    Z = a * d + b * c;
    M = b * d;

    min = gcd(Z, M);
    printf("%d %d\n", Z/min, M/min);
   
    return 0;
}
