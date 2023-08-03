#include<stdio.h>
#include<math.h>
int GCD(int a, int b) {
    int tmp, n;
    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}
int main() {
    int n1, n2;
    int N1, N2;
    int gcd, lcm;
    scanf("%d %d", &n1, &n2);
    N1 = n1;
    N2 = n2;
    gcd = GCD(n1, n2);
    lcm = N1 * N2 / gcd;
    printf("%d\n%d\n", gcd,lcm);
    return 0;
}
