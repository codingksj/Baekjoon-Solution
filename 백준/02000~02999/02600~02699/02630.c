#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define MAX 129

int color_paper[MAX][MAX];
int Bcnt = 0, Wcnt = 0;

int GetSum(int x, int y, int size) {
    int sum = 0;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            sum += color_paper[i][j];
        }
    }
    return sum;
}

void GetBWPaper(int x, int y, int size) {
    int sum = GetSum(x, y, size);
    if (sum == size * size) {
        Bcnt++;
    }
    else if (sum == 0) {
        Wcnt++;
    }
    else {
        GetBWPaper(x, y, size / 2);
        GetBWPaper(x, y + size / 2, size / 2);
        GetBWPaper(x + size / 2, y, size / 2);
        GetBWPaper(x + size / 2, y + size / 2, size / 2);
    }
    return;
}

int main() {
    int size;
    int answer = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &color_paper[i][j]);
        }
    }
    GetBWPaper(0, 0, size);
    printf("%d\n%d\n", Wcnt, Bcnt);
    return 0;
}
