#include <iostream>

using namespace std;

long long count0;
long long count1;

long long fibo[41];

long long fibonacci(int n) {
    if (n == 0 || n == 1);
    else {
        for (int i = 2; i <= n; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
    }
    return fibo[n];
}

int main() {
    int TC, N;

    cin >> TC;

    fibo[0] = 0LL;
    fibo[1] = 1LL;

    while (TC--) {
        count0 = count1 = 0LL;
        cin >> N;
        if (N == 0) {
            count0 = 1LL;
            count1 = 0LL;
        }
        else if (N == 1) {
            count0 = 0LL;
            count1 = 1LL;
        }
        else {
            count0 = fibonacci(N - 1);
            count1 = fibonacci(N);
        }
        printf("%lld %lld\n", count0, count1);
    }
    return 0;
}
