#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr double EPS = 1E-4;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 10;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL N, d;

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
    return;
};

bool Input() {
    cin >> N;

    return true;
};

void Solve() {
    auto Check = [&](LL n) {
        return 3 * n * (n - 1) + 1 >= N;
    };
    LL l = 1, r = 2E+9;
    while (l <= r) {
        LL m = (l + r) / 2;
        if (Check(m)) {
            d = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
};

void Output() {
    println("{}", d);
    return;
};
