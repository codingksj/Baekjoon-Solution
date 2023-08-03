#include <stdio.h>

int main() {
    int N;
    int star;
    int blank;
    int r, c;
    scanf("%d", &N);
    for (r = 1; r < 2 * N; r++) {
        if (r <= N) {
            star = 2 * (N - r) + 1;
            blank = r-1;
        }
        else {
            star = 2 * (r - N) + 1;
            blank = 2 * N - 1 - r;
        }
        for (c = 0; c < blank; c++) {
            printf(" ");
        }
        for (c = 0; c < star; c++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
