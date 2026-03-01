#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<random>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
LL DFS(int s, int e);
LL GetGCD(int s, int e);
void Output();

LL A[MAX];
LL mxBeauty;
int N;

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
    mxBeauty = DFS(0, N - 1);
};

LL DFS(int s, int e) {
    if (s == e) {
        return A[s];
    }
    int m = (s + e + 1) / 2;
    return max(DFS(s, m - 1) + GetGCD(m, e), DFS(m, e) + GetGCD(s, m - 1));
};

LL GetGCD(int s, int e) {
    int g = 0;
    for (int i = s; i <= e; i++) {
        g = gcd(g, A[i]);
    }
    return g;
}

void Output() {
    println("{}", mxBeauty);
    return;
};
