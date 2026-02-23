#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>
#include<random>

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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1000;
    constexpr auto Rng = views::iota;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int A[MAX][MAX];
int TC, N;
bool isHom;

int main() {
    FastIO();
    SetUp();

    while (Input()) {
        Solve();
        Output();
    }

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

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> A[r][c];
        }
    }

    return N;
};

void Solve() {
    isHom = true;

    if (N == 1) {
        return;
    }
    for (int r = 1; r < N; r++) {
        int diff = A[0][0] - A[r][0];
        for (int c = 0; c < N; c++) {
            if (A[0][c] - A[r][c] != diff) {
                isHom = false;
                return;
            }
        }
    }
};

void Output() {
    println("{}", isHom ? "homogeneous" : "not homogeneous");
    return;
};
