#include <stdio.h>

int main() {
    int N;
    int count = 0;
    int i;
    int a1, a2, a3;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        if (i < 100) {
            count++;
        }
        else if (i < 1000) {
            a1 = i / 100;
            a2 = (i / 10) % 10;
            a3 = i % 10;
            if ((a1 + a3) == 2 * a2) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}