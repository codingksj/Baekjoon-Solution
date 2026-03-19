#include<bits/stdc++.h>
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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+6;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL pfB[MAX + 1];
bool sgn[MAX + 1];
LL S, M = 1;
int N, b;

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

    for (int i : Rng(1, N + 1)) {
        cin >> sgn[i];
    }
    for (int i : Rng(1, N + 1)) {
        cin >> b;
        if (!sgn[i]) {
            b *= -1;
        }
        pfB[i] = pfB[i - 1] + b;
    }
    return true;
};

void Solve() {
    S = pfB[N] - pfB[0];
    for (int i = 1; i <= N;i++) {
        LL s = pfB[N] - pfB[i];
        if (s > 0) {
            S += s;
            M++;
        }
    }
};

void Output() {
    println("{} {}", M, S);
    return;
};
