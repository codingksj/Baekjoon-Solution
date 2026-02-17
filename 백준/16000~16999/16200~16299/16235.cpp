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
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 5, INF = 0x3f3f3f3f, MAX = 10;
    constexpr int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    constexpr int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
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

V1<int> T[MAX][MAX];
V1<Ti3> dead;
V1<Pii> propagate;
int A[MAX][MAX];
int E[MAX][MAX];
int N, M, K, r, c, val, res;

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
    cin >> N >> M >> K;

    for (int r : Rng(0, N)) {
        for (int c : Rng(0, N)) {
            cin >> A[r][c];
            E[r][c] = 5;
        }
    }
    while (M--) {
        cin >> r >> c >> val;
        T[--r][--c].push_back(val);
    }
    return true;
};

void Solve() {
    auto Spring = [&]() {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                ranges::sort(T[r][c]);
                int sz = T[r][c].size();
                for (int i = 0; i < sz; i++) {
                    int& tree = T[r][c][i];
                    if (E[r][c] < tree) {
                        dead.emplace_back(r, c, sz - i);
                        break;
                    } 
                    E[r][c] -= tree++;
                    if (!(tree % MOD)) {
                        propagate.emplace_back(r, c);
                    }
                }
            }
        }
    };
    auto Summer = [&]() {
        while (!dead.empty()) {
            auto [r, c, cnt] = dead.back(); dead.pop_back();
            while (cnt--) {
                E[r][c] += T[r][c].back() / 2;
                T[r][c].pop_back();
            }
        }
    };
    auto Fall = [&]() {
        while (!propagate.empty()) {
            auto [r, c] = propagate.back(); propagate.pop_back();
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    T[nr][nc].push_back(1);
                }
            }
        }
    };
    auto Winter = [&]() {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                E[r][c] += A[r][c];
            }
        }
    };
    while (K--) {
        Spring();
        Summer();
        Fall();
        Winter();
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            res += T[r][c].size();
        }
    }
    return;
};

void Output() {
    println("{}", res);
    return;
};
