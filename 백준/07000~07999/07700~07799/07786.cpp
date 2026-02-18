#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti4 = tuple<int, int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 11;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL dp[MAX + 1][DIGITS];
LL pow10s[MAX + 1] = { 1, };
LL L, U, res;

int main() {
    FastIO();
    SetUp();

    Input();
    Solve();
    Output();

    return 0;
}

void FastIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return;
};

void SetUp() {
    for (int i = 1; i <= MAX; i++) {
        pow10s[i] = pow10s[i - 1] * 10;
    }
    for (int i = 0; i < DIGITS; i++) {
        dp[1][i] = i;
    }
    for (int l = 2; l <= MAX; l++) {
        for (int i = 0; i < DIGITS; i++) {
            dp[l][0] += dp[l - 1][i];
        }
        for (int i = 1; i < DIGITS; i++) {
            dp[l][i] = dp[l][0] + i * pow10s[l - 1];
        }
    }
    return;
};

bool Input() {
    cin >> L >> U;

    return true;
};

void Solve() {
    auto F = [&](LL N) {
        if (N <= 0) {
            return 0LL;
        }
        string s = to_string(N);
        LL sum = 0;
        int len = s.size();
        for (int l = len; l > 0; l--) {
            LL d = s[len - l] - '0';
            for (int i = 0; i < d; i++) {
                sum += dp[l][i];
            }
            N %= pow10s[l - 1];
            sum += d * (N + 1);
        }
        return sum;
    };
    res = F(U) - F(L - 1);
};

void Output() {
    println("{}", res);
    return;
};
