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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50000;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<string> mp;
int dr[6] = { -1, 0, 1, 1, 0, -1 }; 
int dc[2][6] = { { 0, 1, 0, -1, -1, -1 } ,{ 1, 1, 1, 0, -1, 0 }};
int N, M, beach;

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
    cin >> N >> M;

    mp.resize(N);

    for (int i : Rng(0, N)) {
        cin >> mp[i];
    }

    return true;
};

void Solve() {
    auto Ok = [&](int r, int c) {
        return !(r < 0 || r >= N || c < 0 || c >= M);
    };
    for (int r : Rng(0, N)) {
        for (int c : Rng(0, M)) {
            if (mp[r][c] == '#') {
                for (int i = 0; i < 6; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[r & 1][i];
                    if (Ok(nr, nc)) {
                        beach += mp[r][c] != mp[nr][nc];
                    }
                }
            }
        }
    }
};

void Output() {
    println("{}", beach);
    return;
};
