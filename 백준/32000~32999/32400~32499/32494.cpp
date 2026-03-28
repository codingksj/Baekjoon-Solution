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
void Output();

V1<PLL> A;
V1<Ti3> edges;
LL sz[MAX + 1];
LL counts[MAX + 1];
LL pSum[MAX + 1];
int par[MAX + 1];
int vals[MAX + 1];
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
    cin >> N >> Q;

    edges.resize(N - 1);

    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
    }

    return true;
};

void Solve() {
    iota(par + 1, par + N + 1, 1);
    ranges::fill(sz, sz + N + 1, 1);
    ranges::sort(edges);
    auto Find = [](auto&& self, int v) -> int {
        return v == par[v] ? v : par[v] = self(self, par[v]);
    };
    auto Union = [&](int u, int v, int w) {
        u = Find(Find, u);
        v = Find(Find, v);
        if (u < v) {
            swap(u, v);
        }
        par[u] = v;
        A.emplace_back(w, sz[u] * sz[v]);
        sz[v] += sz[u];
    };
    for (const auto& [w, u, v] : edges) {
        Union(u, v, w);
    }
    ranges::sort(A);
    vals[1] = A[0].first;
    int cnt = 1;
    for (const auto& [w, n] : A) {
        if (w != vals[cnt]) {
            vals[++cnt] = w;
        }
        counts[cnt] += n;
    }
    for (int i = 1; i <= cnt; i++) {
        pSum[i] = pSum[i - 1] + counts[i] * vals[i];
    }
    while (Q--) {
        cin >> u >> v;
        int i1 = ranges::lower_bound(vals + 1, vals + cnt + 1, u) - vals;
        int i2 = ranges::upper_bound(vals + 1, vals + cnt + 1, v) - vals - 1;
        println("{}", pSum[i2] - pSum[i1 - 1]);
    }
};

void Output() {
    return;
};
