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
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

namespace PAPERS {
    enum OBJ { PAPER, EMPTY, SIDE = 10, AREA = 100, MAX_SIZE = 5};
}
using namespace PAPERS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int pos, int cnt);
bool CanPlace(int sr, int sc, int size);
void Fill(int sr, int sc, int size, int obj);
void Output();

int P[AREA];
int paperCnt[MAX_SIZE + 1] = { 0,5,5,5,5,5 };
int mnPaper = INF;
int N, oneCnt;

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
    for (int i : Rng(0, AREA)) {
        cin >> P[i];
        if (P[i]) {
            oneCnt++;
        }
    }
    return true;
};

void Solve() {
    DFS(0, 0);
    return;
};

void DFS(int pos, int cnt) {
    if (!oneCnt) {
        mnPaper = min(mnPaper, cnt);
        return;
    }
    if (cnt >= mnPaper) {
        return;
    }
    if (pos == AREA) {
        mnPaper = min(mnPaper, cnt);
        return;
    }
    if (P[pos] == PAPER) {
        DFS(pos + 1, cnt);
    }
    else {
        for (int n = 5; n > 0; n--) {
            int sr = pos / SIDE;
            int sc = pos % SIDE;
            if (paperCnt[n] && CanPlace(sr, sc, n)) {
                Fill(sr, sc, n, PAPER);
                paperCnt[n]--;
                oneCnt -= n * n;
                DFS(pos + 1, cnt + 1);
                oneCnt += n * n;
                paperCnt[n]++;
                Fill(sr, sc, n, EMPTY);
            }
        }
    }
};

bool CanPlace(int sr, int sc, int size) {
    if (sr + size - 1 >= SIDE || sc + size - 1 >= SIDE) {
        return false;
    }
    for (int r = sr; r < sr + size; r++) {
        for (int c = sc; c < sc + size; c++) {
            if (P[r * SIDE + c] != EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void Fill(int sr, int sc, int size, int obj) {
    for (int r = sr; r < sr + size; r++) {
        for (int c = sc; c < sc + size; c++) {
            P[r * SIDE + c] = obj;
        }
    }
}

void Output() {
    println("{}", mnPaper == INF ? -1 : mnPaper);
    return;
};
