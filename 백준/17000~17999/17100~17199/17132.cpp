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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
    constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
int Find(int v);
void Output();

V1<Ti3> edges;
int sz[MAX + 1];
int par[MAX + 1];
LL res;
int N, Q, u, v, w;

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

    edges.resize(N - 1);

    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
    }
    return true;
};

void Solve() {
    for (int i : Rng(1, MAX + 1)) {
        par[i] = i, sz[i] = 1;
    }
    ranges::sort(edges, greater<Ti3>());
    for (auto& [w, u, v] : edges) {
        u = Find(u), v = Find(v);
        if (u < v) {
            swap(u, v);
        }
        par[u] = v;
        res += (LL)w * sz[u] * sz[v];
        sz[v] += sz[u];
    }
};

int Find(int v) {
    return v == par[v] ? v : par[v] = Find(par[v]);
};

void Output() {
    println("{}", res);
    return;
};
