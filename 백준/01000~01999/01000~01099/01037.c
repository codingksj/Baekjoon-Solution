#include<stdio.h>
#include<math.h>
int main() {
    int max = -1,min = 1000001;
    int div[51] = { 0, };
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &div[i]);
    }
    for(int i = 0; i < n; i++) {
        if (max < div[i])
            max = div[i];
        if (min > div[i])
            min = div[i];
    }
    printf("%d", max * min);
    return 0;
}
