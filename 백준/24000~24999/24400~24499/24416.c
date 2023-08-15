#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int f[41] = {0,};

    scanf("%d", &n);

    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    printf("%d %d", f[n], n - 2);
   
}