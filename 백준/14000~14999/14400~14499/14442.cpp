#include<bits/stdc++.h>
#include<unordered_set>
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
    constexpr double EPS = 1E-4;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1'000, MAX_K = 10;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

struct Info {
    int r;
    int c;
    int wallCnt;
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

queue<Info> q;
int dists[MAX_K + 1][MAX + 1][MAX + 1];
bool A[MAX + 1][MAX + 1];
int R, C, K, mnDist = INF;
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
    memset(dists, 0x3f, sizeof(dists));
    return;
};

bool Input() {
    cin >> R >> C >> K;

    for (int r : Rng(0, R)) {
        for (int c : Rng(0, C)) {
            cin >> ch;
            A[r][c] = ch == '1';
        }
    }

    return true;
};

void Solve() {
    q.emplace(0, 0, 0);

    dists[0][0][0] = 1;

    auto Ok = [&](int r, int c) {return r >= 0 && r < R && c >= 0 && c < C; };

    while (!q.empty()) {
        auto [r, c, wallCnt] = q.front(); q.pop();
        int dist = dists[wallCnt][r][c];
        int nDist = dist + 1;
        if (r == R - 1 && c == C - 1) {
            mnDist = dist;
            return;
        }
        for (const auto& [dr, dc] : DT4) {
            int nr = r + dr;
            int nc = c + dc;
            if (!Ok(nr, nc)) {
                continue;
            }
            if (!A[nr][nc] && dists[wallCnt][nr][nc] > nDist) {
                q.emplace(nr, nc, wallCnt);
                dists[wallCnt][nr][nc] = nDist;
            }
            else if (wallCnt < K && dists[wallCnt + 1][nr][nc] > nDist) {
                q.emplace(nr, nc, wallCnt + 1);
                dists[wallCnt + 1][nr][nc] = nDist;
            }
        }
    }
};

void Output() {
    println("{}", mnDist == INF ? -1 : mnDist);
    return;
};
