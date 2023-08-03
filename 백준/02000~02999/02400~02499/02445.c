#include <stdio.h>

int main() {
    int N;
    int star;
    int blank;
    int r, c;
    scanf("%d", &N);
    for (r = 1; r <= 2 * N - 1; r++) {
        if (r <= N) {
            star = r;
            blank = 2 * (N - r);
        }
        else {
            blank = 2 * (r - N);
            star = 2 * N - r;
        }
        //앞
        for (c = 0; c < star; c++) {
            printf("*");
        }
        //중간
        for (c = 0; c < blank; c++) {
            printf(" ");
        }
        //뒤
        for (c = 0; c < star; c++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
