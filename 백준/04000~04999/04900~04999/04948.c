#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int sum;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        int* prime = (int*)malloc((2 * n + 1) * sizeof(int));
        for (int i = 2; i <= 2 * n; i++) {
            prime[i] = 1;
        }

        for (int p = 2; p * p <= 2 * n; p++) {
            if (prime[p] == 1) {
                for (int i = p * p; i <= 2 * n; i += p) {
                    prime[i] = 0;
                }
            }
        }

        sum = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (prime[i] == 1) {
                sum++;
            }
        }
        printf("%d\n",sum);

        // 동적 할당된 메모리 해제
        free(prime);
    }

    return 0;
}
