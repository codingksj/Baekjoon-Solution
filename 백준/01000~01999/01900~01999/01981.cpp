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
using Ti4 = tuple<int, int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 100;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
bool Check(int target);
bool BFS(int L, int R);
void Output();

V1<int> V;
bool visChk[MAX][MAX];
unsigned char A[MAX][MAX];
int N, val, res;

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

    for (int r : Rng(0, N)) {
        for (int c : Rng(0, N)) {
            cin >> val;
            A[r][c] = val;
            V.push_back(val);
        }
    }
    
    return true;
};

void Solve() {
    ranges::sort(V);
    auto [st, ed] = ranges::unique(V);
    V.erase(st, ed);
    int l = 0, r = 2 * MAX;
    while (l <= r) {
        int m = (l + r) / 2;
        if (Check(m)) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return;
};

bool Check(int target) {
    for (int L : V) {
        int R = L + target;
        int st = A[0][0];
        int ed = A[N - 1][N - 1];
        if (st < L || st > R || ed < L || ed > R) {
            continue;
        }
        if (BFS(L, R)) {
            return true;
        }
    }
    return false;
}

bool BFS(int L, int R) {
    queue<Pii> q;

    memset(visChk, false, sizeof(visChk));
    q.emplace(0, 0);
    visChk[0][0] = true;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == N - 1 && c == N - 1) {
            return true;
        }
        for (const auto& [dr, dc] : DT4) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= N || nc < 0 || nc >= N || visChk[nr][nc]) {
                continue;
            } 
            if (A[nr][nc] >= L && A[nr][nc] <= R) {
                visChk[nr][nc] = true;
                q.push({ nr, nc });
            }
        }
    }
    return false;
};

void Output() {
    println("{}", res);
    return;
};
