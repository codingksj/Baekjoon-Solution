#include <stdio.h>

#define MAX 51

char newspaper[MAX][MAX];

int main() {
    int R, C, ZR, ZC;
    scanf("%d %d %d %d", &R, &C, &ZR, &ZC);
    for (int i = 0; i < R; i++) {
        scanf("%s", newspaper[i]);
    }
    for (int i = 0; i < R * ZR; i++) {
        for (int j = 0; j < C*ZC; j++) {
            printf("%c", newspaper[i / ZR][j / ZC]);
        }
        printf("\n");
    }
    return 0;
}
