#include<stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int arr[1000001];

int main() {
    int X;
    int i;
    scanf("%d", &X);
    arr[1] = 0;
    for (i = 2; i <= X; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
        if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    printf("%d", arr[X]);
    return 0;
}
