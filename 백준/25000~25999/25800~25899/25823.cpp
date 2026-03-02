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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
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

LL f[2 * MAX + 1] = { 1, };
LL invF[MAX + 1] = { 1, };
LL M, res;

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
    for (LL n = 1; n <= 2 * MAX; n++) {
        f[n] = f[n - 1] * n % MOD;
    }
    auto PowMod = [&](LL base, LL exp) {
        LL res = 1;
        for (; exp; exp >>= 1, base = base * base % MOD) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
        };
        return res;
    };
    invF[MAX] = PowMod(f[MAX], MOD - 2);
    for (LL n = MAX - 1; n >= 0; n--) {
        invF[n] = invF[n + 1] * (n + 1) % MOD;
    }
    return;
};

bool Input() {
    cin >> M;

    return true;
};

void Solve() {
    LL head = 1;
    LL body = 1;
    LL term = 0;
    for (int m = 3; m <= M; m++) {
        head = f[2 * m];
        body = invF[m] * invF[m] % MOD;
        term = head * body % MOD;
        res += term;
        if (res >= MOD) {
            res -= MOD;
        }
    }
};

void Output() {
    println("{}", res);
    return;
};
