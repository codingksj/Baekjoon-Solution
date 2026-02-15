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
using Coord = array<int, 11>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr string_view target = "long";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 750;
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

int diagM[MAX + 1][MAX + 1];
int diagA[MAX + 1][MAX + 2];
string mine[MAX + 1];
int R, C, mxDia;

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
        cin >> mine[r];
        mine[r] += "00";
    }
    return true;
};

void Solve() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++){
            if (mine[r - 1][c - 1] == '1') {
                diagM[r][c] = diagM[r - 1][c - 1] + 1;
            }
            if (mine[r - 1][C - c] == '1') {
                diagA[r][C - c + 1] = diagA[r - 1][C - c + 2] + 1;
            }
        }
    }
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++){
            int len = min(diagM[r][c], diagA[r][c]);
            for (int l = len; l > mxDia; l--) {
                int targetR = r - l + 1;
                int leftC = c - l + 1;
                int rightC = c + l - 1;
                if (targetR < 1 || leftC < 1 || rightC > C) {
                    continue;
                }
                if (diagA[targetR][leftC] < l || diagM[targetR][rightC] < l) {
                    continue;
                }
                mxDia = max(mxDia, l);
                break;
            }
        }
    }
    return;
};

void Output() {
    println("{}", mxDia);
    return;
};
