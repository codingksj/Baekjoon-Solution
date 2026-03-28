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
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int S[5] = { 0, 3, 6, 8, 10 };
int mxS, s, d;

int main() {
    FastIO();
    SetUp();

    while (Input()) {
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
    return;
};

bool Input() {
    return (bool)(cin >> s >> d);
};

void Solve() {
    mxS = -1;
    for (int i = 4; i >= 0; i--) {
        int sum = i * s + (i - 5) * d;
        if (sum < 0) {
            mxS = S[i] * s + (S[i] - 12) * d;
            return;
        }
    }
};

void Output() {
    println("{}", mxS < 0 ? "Deficit" : to_string(mxS));
};
