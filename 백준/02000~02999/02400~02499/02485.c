#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int N;
    int arr[100001] = { 0, };
    int delta[100001] = { 0, };
    int length;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    length = arr[N - 1] - arr[0];
    for (int i = 1; i < N; i++) {
        delta[i] = arr[i] - arr[i-1];
    }
    for (int i = 2; i < N; i++) {
        delta[i] = gcd(delta[i], delta[i - 1]);
    }
    printf("%d", length / delta[N - 1] - N + 1);
    return 0;
}
