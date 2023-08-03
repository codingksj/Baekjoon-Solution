#include <stdio.h>

#define MAX 1000000 + 1

long long lan_cable[MAX];

long long GetArraySum(long long arr[], long long cut, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (arr[i]/cut);
    }
    return sum;
}

int main(){
    int K, N;
    
    long long M = 0, m = (2LL << 31);
    long long left, right, mid;
    long long sum, result;

    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &lan_cable[i]);
        M = (M > lan_cable[i]) ? M : lan_cable[i];
        m = (m < lan_cable[i]) ? m : lan_cable[i];
    }
    
    left = 1;
    right = M;

    while(left<=right) {
        mid = (left + right) / 2LL;
        sum = GetArraySum(lan_cable, mid, K);
        if (sum >= N) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("%lld\n", result);
    return 0;
}