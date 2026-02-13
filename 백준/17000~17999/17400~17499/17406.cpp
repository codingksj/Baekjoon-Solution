#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using UC = unsigned char;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr Pii NONE = { -1,-1 };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 50;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

struct Rotation {
    int r, c, s;
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void Rotate(int idx);
void Output();

UC A[MAX + 1][MAX + 1], B[MAX + 1][MAX + 1];
Rotation R[1 << 3];
int idx[1 << 3];
int N, M, K, r, c, s, val, totalMn = INF;

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
        for (int c : Rng(0, M)) {
            cin >> val;
            A[r][c] = val;
        }
    }
    for (int i : Rng(0, K)) {
        cin >> r >> c >> s;
        R[i] = { --r, --c, s };
    }
    return true;
};

void Solve() {
    iota(idx, idx + K, 0);
    do {
        for (int i = 0; i < N; i++) {
            memcpy(B[i], A[i], sizeof(UC) * M);
        }
        for (int i = 0; i < K; i++) {
            Rotate(idx[i]);
        }
        int mnSum = INF;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += B[i][j];
            }
            mnSum = min(sum, mnSum);
        }
        totalMn = min(totalMn, mnSum);
    } while (next_permutation(idx, idx + K));
    return;
};

void Rotate(int idx) {
    const auto& [cr, cc, s] = R[idx];
    for (int i = s; i > 0;i--) {
        int sr = cr - i;
        int sc = cc + i;
        UC tmp = B[sr][sc];
        for (int j = 3; j >= 0; j--) {
            const auto& [dr, dc] = DT4[j];
            for (int k = 0; k < 2 * i; k++) {
                B[sr][sc] = B[sr + dr][sc + dc];
                sr += dr, sc += dc;
            }
        }
        const auto& [dr, dc] = DT4[0];
        B[sr - dr][sc - dc] = tmp;
    }
};

void Output() {
    println("{}", totalMn);
    return;
};
