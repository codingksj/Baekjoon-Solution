#include <bits/stdc++.h>
#include <ranges>
#include <print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;

template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 12;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int digits[MAX];
LL pow10s[MAX] = { 1 };
LL res, N;
int TC;

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while (TC--) {
        Input();
        Solve();
        Output();
    }

    return 0;
}

void FastIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return;
};

void SetUp() {
    for (int i = 1; i < MAX; i++) {
        pow10s[i] = pow10s[i - 1] * 10;
    }
    return;
};

bool Input() {
    return (bool)(cin >> N);
};

void Solve() {
    int cnt = 0;
    for (LL t = N; t; digits[cnt++] = t % 10, t /= 10) {};
    LL half = pow10s[cnt] / 2 - 1;
    LL rev = 0;
    N = min(N, half);
    for (LL t = N, cnt = 0; t; rev += (9 - t % 10) * pow10s[cnt++], t /= 10) {};
    res = N * rev;
};

void Output() {
    println("{}", res);
};
