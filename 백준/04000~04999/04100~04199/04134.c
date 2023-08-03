#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(long long x) {
    if (x == 0 || x == 1)
        return 0;
    for (long long i = 2; i < (sqrt(x) + 1); i++) {
        if (x % i == 0 && i != x)
            return 0;
    }
    return 1;
}

int main() {
    long long N;
    long long num;
    long long P;
    scanf("%lld", &N);
    while (N--) {
        scanf("%lld", &num);
        P = num;
        while (1) {
            if (IsPrime(P)) {
                printf("%lld\n", P);
                break;
            }
            else {
                P++;
            }
        }
    }

    return 0;
}
