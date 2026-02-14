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
using Ptr = const int*;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2'000;
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

int A[MAX][MAX];
int pfA[MAX + 1][MAX + 1];
int N, M, K, S, R, C, val;

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
    cin >> N >> M >> K >> S;

    for (int r = 0; r < N; r++) {
        for (int c = 0, rSum = 0; c < M; c++) {
            cin >> val;
            A[r][c] = val;
            rSum += val;
            pfA[r + 1][c + 1] = pfA[r][c + 1] + rSum;
        }
    }
    return true;
};

void Solve() {
    R = (N - K) / S;
    C = (M - K) / S;
    const int d = K / 2;
    auto F = [&](int r1, int c1, int r2, int c2) {
        return pfA[r2 + 1][c2 + 1] - pfA[r1][c2 + 1] - pfA[r2 + 1][c1] + pfA[r1][c1];
    };
    for (int r = 0, centerR = d; r <= R; r++, centerR += S) {
        for (int c = 0, centerC = d; c <= C; c++, centerC += S) {
            int r1 = centerR - d, r2 = centerR + d;
            int c1 = centerC - d, c2 = centerC + d;
            int s1 = F(centerR, c1, centerR, c2);
            int s2 = F(r1, centerC, r2, centerC);
            print("{}{}", s1 + s2 - A[centerR][centerC], SEPS[c == C]);
        }
    }
    return;
};

void Output() {
    return;
};
