#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, ans;
    scanf("%d",&n);
    ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
    }
    printf("%d", ans);
    return 0;
}
