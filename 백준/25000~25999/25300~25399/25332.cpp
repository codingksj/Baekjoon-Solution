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
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
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

map<int, LL> mp;
int A[MAX + 2];
int B[MAX + 2];
LL totalCnt;
int val, N;

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

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }
    return true;
};

void Solve() {
    for (int i : Rng(0, N)) {
        cin >> val;
        A[i] -= val;
        B[i + 1] = B[i] + A[i];
        mp[B[i + 1]]++;
    }
    totalCnt = mp[0];
    for (const auto& [n, cnt] : mp) {
        totalCnt += cnt * (cnt - 1) / 2;
    }
    return;
};

void Output() {
    println("{}", totalCnt);
    return;
};
