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
using Pot = int[3];
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1'000, SHIFT = 8;
    constexpr int dr8[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    constexpr int dc8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void BFS(int sr, int sc);
bool Ok(int r, int c);
void Output();

int A[MAX][MAX];
bitset<MAX> visChk[MAX];
queue<Pii> q;
int R, C, color, cnt;

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
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int rgb = 0;
            for (int i = 0; i < 3; i++) {
                cin >> color;
                rgb |= color << (SHIFT * i);
            }
            A[r][c] = rgb;
        }
    }
    return true;
};

void Solve() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!visChk[r][c]) {
                cnt++;
                BFS(r, c);
            }
        }
    }
    return;
};

void BFS(int sr, int sc) {
    q.push(Pii(sr, sc));
    visChk[sr][sc] = true;
    int color = A[sr][sc];
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = r + dr8[i];
            int nc = c + dc8[i];
            if (!Ok(nr, nc) || visChk[nr][nc] || color != A[nr][nc]) {
                continue;
            }
            q.emplace(nr, nc);
            visChk[nr][nc] = true;
        }
    }
};

bool Ok(int r, int c) {
    return !(r < 0 || r >= R || c < 0 || c >= C);
}

void Output() {
    println("{}", cnt);
    return;
};
