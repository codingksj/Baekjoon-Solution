#include<bits/stdc++.h>
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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 2E+5;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int prv, int v, int color);
void Output();

V1<int> G[MAX];
int C[MAX];
int N, v1, v2;
int mnColor = 2;
bool isBi = true;

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
        cin >> v1 >> v2;
        G[--v1].push_back(--v2);
        G[v2].push_back(v1);
    }

    return true;
};

void Solve() {
    memset(C, -1, sizeof(int) * N);
    DFS(-1, 0, 0);
    mnColor += !isBi;
};

void DFS(int prv, int v, int color) {
    if (C[v] != -1) {
        return;
    }
    C[v] = color;
    for (int nv : G[v]) {
        if (nv == prv) {
            continue;
        }
        if (C[nv] == color) {
            isBi = false;
            continue;
        }
        DFS(v, nv, !color);
    }
};

void Output() {
    println("{}", mnColor);
    return;
};
