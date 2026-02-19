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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50000;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

bitset<MAX + 1> dp;
V1<Pii> coins;
int TC = 3, N;
bool canSplit;

int main() {
    FastIO();
    SetUp();

    while(TC--) {
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
    return;
};

bool Input() {
    cin >> N;

    return true;
};

void Solve() {
    int sum = 0;

    coins.resize(N);

    for (auto& [coin, cnt] : coins) {
        cin >> coin >> cnt;
        sum += coin * cnt;
    }
    if (sum & 1) {
        canSplit = false;
        return;
    }
    dp.reset();

    int half = 0;

    canSplit = false;
    dp[0] = true;

    auto Cmp = [&](const Pii& p1, const Pii& p2) {
        return p1.second != p2.second ? p1.second > p2.second : p1.first > p2.first;
    };
    ranges::sort(coins, Cmp);
    half = sum / 2;
    for (const auto& [coin, cnt] : coins) {
        for (int i = 1; i <= cnt; i++) {
            dp |= (dp << coin);
        }
        if (dp[half]) {
            canSplit = true;
            return;
        }
    }
};

void Output() {
    println("{}", (int)canSplit);
    return;
};
