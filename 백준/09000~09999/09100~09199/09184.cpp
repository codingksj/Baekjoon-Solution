#include <iostream>
using namespace std;

long long w[21][21][21];

long long GetWabc(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1LL;
    }
    if (a > 20 || b > 20 || c > 20) {
        return (1LL << 20);
    }
    if (w[a][b][c]) {
        return w[a][b][c];
    }
    if (a < b && b < c) {
        w[a][b][c] = GetWabc(a, b, c - 1) + GetWabc(a, b - 1, c - 1) - GetWabc(a, b - 1, c);
        return w[a][b][c];
    }
    w[a][b][c] = GetWabc(a - 1, b, c) + GetWabc(a - 1, b - 1, c) + GetWabc(a - 1, b, c - 1) - GetWabc(a - 1, b - 1, c - 1);
    return w[a][b][c];
}

int main() {
    long long answer = 0;
    long long a, b, c;

    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        else {
            answer = GetWabc(a, b, c);
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, answer);
        }

    }
    return 0;
}
