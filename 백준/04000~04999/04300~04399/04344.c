#include <stdio.h>

int main() {
    int TC, N, cnt;
    int students[1001] = { 0, };
    double sum, avg, res;
    scanf("%d", &TC);
    while (TC--) {
        sum = avg = res = 0.0;
        cnt = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &students[i]);
            sum += students[i];
        }
        avg = sum / N;
        for (int i = 0; i < N; i++) {
            if (avg < students[i]) {
                cnt++;
            }
        }
        res = (cnt * 100) / (double)N;
        printf("%.3f%%\n", res);
        
    }
    return 0;
}