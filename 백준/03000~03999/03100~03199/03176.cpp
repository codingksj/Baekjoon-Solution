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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
    constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int v, int d, int p);
void Output();

V1<Pii> G[MAX + 1];
int par[bit_width(MAX + 1)][MAX + 1];
int mxD[bit_width(MAX + 1)][MAX + 1];
int mnD[bit_width(MAX + 1)][MAX + 1];
int depth[MAX + 1];
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
    memset(mnD, 0x3f, sizeof(mnD));
    return;
};

bool Input() {
    cin >> N;

    for (int i : Rng(0, N - 1)) {
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    cin >> Q;

    return true;
};

void Solve() {
    DFS(1, 0, 0);
    int mxLv = bit_width((ULL)N);
    for (int lv : Rng(1, mxLv)) {
        for (int i = 1; i <= N; i++) {
            int p = par[lv - 1][i];
            if (p) {
                par[lv][i] = par[lv - 1][p];
                mxD[lv][i] = max(mxD[lv - 1][i], mxD[lv - 1][p]);
                mnD[lv][i] = min(mnD[lv - 1][i], mnD[lv - 1][p]);
            }
        }
    }
    auto Query = [&](int u, int v) {
        if (u == v) {
            return Pii(0, 0);
        }
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        int diff = depth[v] - depth[u];
        int mn = INF;
        int mx = 0;
        for (int lv = 0; diff; lv++, diff >>= 1) {
            if (diff & 1) {
                mn = min(mn, mnD[lv][v]);
                mx = max(mx, mxD[lv][v]);
                v = par[lv][v];
            }
        }
        if (u == v) {
            return Pii(mn, mx);
        }
        for (int lv = mxLv - 1; lv >= 0; lv--) {
            if (par[lv][u] != par[lv][v]) {
                mn = min({ mn, mnD[lv][u], mnD[lv][v] });
                mx = max({ mx, mxD[lv][u], mxD[lv][v] });
                u = par[lv][u];
                v = par[lv][v];
            }
        }
        mn = min({ mn, mnD[0][v], mnD[0][u]});
        mx = max({ mx, mxD[0][v], mxD[0][u]});
        return Pii(mn, mx);
    };
    while (Q--) {
        cin >> u >> v;
        const auto& [mn, mx] = Query(u, v);
        println("{} {}", mn, mx);
    }
};

void DFS(int v, int d, int p) {
    par[0][v] = p;
    depth[v] = d;
    for (const auto& [nv, w] : G[v]) {
        if (nv != p) {
            mxD[0][nv] = w;
            mnD[0][nv] = w;
            DFS(nv, d + 1, v);
        }
    }
};

void Output() {
    return;
};
