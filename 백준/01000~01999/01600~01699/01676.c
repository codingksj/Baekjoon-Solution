#include<stdio.h>
#include<math.h>

int main() {
    int n;
    int cnt0=0;
    scanf("%d", &n);
    if (n < 5) {
        printf("0\n");
        return 0;
    }
    else {
        for (int i = 5; i <= n; i++) {
            if (i % 5 == 0)cnt0++;
            if (i % 25 == 0)cnt0++;
            if (i % 125 == 0)cnt0++;
        }
            
    }
    printf("%d\n", cnt0);
    return 0;
}
