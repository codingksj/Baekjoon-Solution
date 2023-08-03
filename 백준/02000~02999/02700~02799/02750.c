#include<stdio.h>

int N[2001];

int main() {
    int n, in;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in);
        N[in + 1000]++;
    }
    for (int i = -1000; i <= 1000; i++) {
        for (int j = 0; j < N[i + 1000]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}
