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
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 300;
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

bitset<MAX + 1> A[MAX + 1];
int R, C, killer;
string s;

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

    for (int r = 0; r < R;r++) {
        cin >> s;
        for (int c = 0; c < C; c++) {
            A[r][c] = s[c] - '0';
        }
    }
    return true;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
};

void Solve() {
    auto FindOdd = [&](int r, int c) {
        int sq = 0;
        for (int sz = 1, k = 0;; sz += 2, k++) {
            if (r - k < 0 || r + k >= R || c - k < 0 || c + k >= C) {
                return sq;
            }
            int sr = r - k, sc = c + k;
            int er = r + k, ec = c - k;
            for (int cnt = 0; cnt < sz - 1; cnt++) {
                if (A[sr++][sc] != A[er--][ec]) {
                    return sq;
                }
            }
            for (int cnt = 0; cnt < sz - 1; cnt++) {
                if (A[sr][sc--] != A[er][ec++]) {
                    return sq;
                }
            }
            sq = sz;
        }
        return sq;
    };
    auto FindEven = [&](int r, int c) {
        int r1 = r, r2 = r + 1;
        int c1 = c, c2 = c + 1;
        int sq = 0;
        for (int sz = 2, k = 0;; sz += 2, k++) {
            if (r1 - k < 0 || r2 + k >= R || c1 - k < 0 || c2 + k >= C) {
                return sq;
            }
            int sr = r1 - k, sc = c2 + k;
            int er = r2 + k, ec = c1 - k;
            for (int cnt = 0; cnt < sz - 1; cnt++) {
                if (A[sr++][sc] != A[er--][ec]) {
                    return sq;
                }
            }
            for (int cnt = 0; cnt < sz - 1; cnt++) {
                if (A[sr][sc--] != A[er][ec++]) {
                    return sq;
                }
            }
            sq = sz;
        }
        return sq;
    };
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int odd = FindOdd(r, c);
            int even = FindEven(r, c);
            killer = max(killer, max(odd, even));
        }
    }
    return;
};

void Output() {
    println("{}", killer ? killer : -1);
    return;
};
