#include<bits/stdc++.h>
#include<ranges>
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
    constexpr string_view SEPS = " \n", RES = "-0+";
    constexpr Pii DT4[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    constexpr Pii DT9[9] = { {0, 0}, {0, 1}, {0, 2}, {1, 0},{1, 1}, {1,2}, {2, 0}, {2, 1}, {2, 2} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 20;
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

bool A[MAX][MAX];
int N, M, a, b, mnCost = INF;
char ch;

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
    cin >> N >> M >> a >> b;

    for (int r : Rng(0, N)) {
        for (int c : Rng(0, M)) {
            cin >> ch;
            A[r][c] = ch == '#';
        }
    }
    return true;
};

void Solve() {
    int visChk[MAX][MAX];
    int q = 0;
    memset(visChk, 0, sizeof(visChk));
    auto CalcCost = [&](int sr, int sc, int k) {
        int cost = 0;
        q++;
        for (int i = 0; i < 9; i++) {
            const auto& [dr, dc] = DT9[i];
            for (int r = 0; r < k; r++) {
                for (int c = 0; c < k; c++) {
                    int tr = sr + dr * k + r;
                    int tc = sc + dc * k + c;
                    visChk[tr][tc] = q;
                    if ((i == 4 || i == 5) && A[tr][tc]) {
                        cost += b;
                    }
                    else if ((i < 4 || i > 5) && !A[tr][tc]) {
                        cost += a;
                    }
                }
            }
        }
        for (int r : Rng(0, N)) {
            for (int c : Rng(0, M)) {
                if (visChk[r][c] != q && A[r][c]) {
                    cost += b;
                }
            }
        }
        return cost;
    };
    for (int r : Rng(0, N)) {
        for (int c : Rng(0, M)) {
            int limit = min(N - r, M - c);
            for (int k = 1; 3 * k <= limit; k++) {
                mnCost = min(mnCost, CalcCost(r, c, k));
            }
        }
    }
};

void Output() {
    println("{}", mnCost);
    return;
};
