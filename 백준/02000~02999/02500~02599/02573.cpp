#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<random>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 300, MAX_ICE = 1E+4;
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

V1<Pii> pos, nPos;
int A[MAX][MAX];
int melts[MAX_ICE];
int R, C, mnT;

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

    for (int r : Rng(0, R)) {
        for (int c : Rng(0, C)) {
            cin >> A[r][c];
            if (A[r][c]) {
                pos.push_back({ r,c });
            }
        }
    }

    return true;
};

void Solve() {
    auto Ok = [&](int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    };
    auto Melt = [&] {
        int sz = pos.size();
        for (int i = 0; i < sz; i++) {
            const auto& [r, c] = pos[i];
            for (const auto& [dr, dc] : DT4) {
                int nr = r + dr;
                int nc = c + dc;
                if (Ok(nr, nc) && !A[nr][nc]) {
                    melts[i]++;
                }
            }
        }
        nPos.clear();
        for (int i = 0; i < sz; i++) {
            const auto& [r, c] = pos[i];
            A[r][c] = max(0, A[r][c] - melts[i]);
            if (A[r][c] > 0) {
                nPos.push_back(pos[i]);
            }
            melts[i] = 0;
        }
        swap(pos, nPos);
    };
    auto IsSplit = [&] {
        if (pos.empty()) {
            return false;
        }
        static queue<Pii> q;
        static int visChk[MAX][MAX];
        static int id = 0;
        id++;
        while (!q.empty()) {
            q.pop();
        }
        const auto& [stR, stC] = pos[0];
        q.emplace(stR, stC);
        visChk[stR][stC] = id;
        int visCnt = 0;
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            visCnt++;
            for (const auto& [dr, dc] : DT4) {
                int nr = r + dr, nc = c + dc;
                if (Ok(nr, nc) && A[nr][nc] > 0 && visChk[nr][nc] != id) {
                    visChk[nr][nc] = id;
                    q.push({ nr, nc });
                }
            }
        }
        return visCnt < pos.size();
    };
    for (int t = 0; !pos.empty(); t++) {
        if (IsSplit()) {
            mnT = t;
            return;
        }
        Melt();
    }
};

void Output() {
    println("{}", mnT);
    return;
};
