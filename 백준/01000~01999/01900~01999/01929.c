#include<stdio.h>
#include<math.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int prime[1000001] = {0,};

    for (int i = 2; i <= n; i++) {
        prime[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 0)
        {
            continue;
        }
        for (int j = i * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }

    for (int i = m; i <= n; i++) {
        if (prime[i] != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
