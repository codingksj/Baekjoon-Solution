#include<stdio.h>
#include<math.h>
int main() {
    double sum;
    int TC, n;
    scanf("%d", &TC);

    //로그 성질 이용, 지수가 n이면 n+1 자리 수이다.
    for (int i = 1; i <= TC; i++) {
        scanf("%d", &n);
        sum = 0.0;
        for (int j = 1; j <= n; j++) {
            sum += log10(j);
        }
        printf("%d\n", ((int)sum) + 1);
    }
   
    return 0;
}
