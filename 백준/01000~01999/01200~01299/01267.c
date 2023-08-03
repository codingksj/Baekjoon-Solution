#include <stdio.h>

int main() {
    int Y = 0, M = 0;
    int priceY, priceM;
    int N;
    int call;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &call);
        priceY = 10 * (1 + (call / 30));
        priceM = 15 * (1 + (call / 60));
        Y += priceY;
        M += priceM;
    }
    if (Y < M) {
        printf("Y %d\n", Y);
    }
    else if (M < Y) {
        printf("M %d\n", M);
    }
    else {
        printf("Y M %d\n", M);
    }
    return 0;
}
