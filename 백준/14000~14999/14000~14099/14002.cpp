#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>
#include<random>

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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+3;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, LL n, int mu);
void Output();

V1<int> tails;
int A[MAX];
int lis[MAX];
int dp[MAX];
int N, sz;

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
    for (int i : Rng(0, N)) {
        cin >> A[i];
        int a = A[i];
        if (tails.empty() || tails.back() < a) {
            tails.push_back(a);
            dp[i] = tails.size();
        }
        else {
            auto it = ranges::lower_bound(tails, a);
            *it = a;
            dp[i] = it - tails.begin() + 1;
        }
    }
    int len = tails.size();
    for (int i : Rng(0, N) | views::reverse) {
        if (dp[i] == len) {
            lis[--len] = A[i];
            sz++;
        }
    }
};

void Output() {
    println("{}", sz);
    for (int i = 0;i < sz;i++) {
        print("{}{}", lis[i], SEPS[i == sz - 1]);
    }
    return;
};
