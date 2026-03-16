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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 4E+3;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL res;
int X, Y, N, R;

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
    cin >> X >> Y;

    return true;
};

void Solve() {
    if (X & 1 || X > MAX) {
        return;
    }
    auto PowMod = [](LL b, LL e) {
        LL res = 1;
        for (;e;e >>= 1, b = b * b % MOD) {
            if (e & 1) {
                res = res * b % MOD;
            }
        };
        return res;
    };
    N = (X + Y) / 3, R = X / 2;
    LL powMod3 = PowMod(3, R);
    LL head = 1, body = 1;
    for (int n : Rng(0, R)) {
        head = head * (N - n) % MOD;
        body = body * (n + 1) % MOD;
    }
    res = (head * PowMod(body, MOD - 2)) % MOD;
    res = res * powMod3 % MOD;
};

void Output() {
    println("{}", res);
    return;
};
