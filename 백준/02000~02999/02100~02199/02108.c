#include<stdio.h>
#include<math.h>
int count[8001];
int main() {
    int n, num = 0, cnt = 0, index = 0, max, min;
    int sum = 0;
    int avg = 0;
    int median = 0;
    int mode = 0;
    int range = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
        count[num + 4000]++;
    }

    num = 0;
    for (int i = 0; i < 8001; i++) {
        num += count[i];
        if (num >= (n + 1) / 2) {
            median = i - 4000;
            break;
        }
    }
    max = 0;  
    num = 0;  
    for (int i = 0; i < 8001; i++) {
        if (count[i] > max) {
            max = count[i];
            num = 1;
            mode = i - 4000;
        }
        else if (count[i] == max) {
            if (num == 1) {
                num++;
                mode = i - 4000;
            }
            else {   
                num++;
            }
        }
    }
    max = 0;
    min = 0;
    for (int i = 8000; i >= 0; i--) {
        if (count[i] != 0) {
            max = i;
            break;
        }
    }
    for (int i = 0; i < 8001; i++) {
        if (count[i] != 0) {
            min = i;
            break;
        }
    }
    avg = round(((double)sum / n));
    range = max - min;
    printf("%d\n", avg);
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);
    return 0;
}
