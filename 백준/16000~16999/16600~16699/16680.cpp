#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<unordered_set>
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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+8;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL N, K;
int TC;
bool isSubin;

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while (TC--) {
        Input();
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

    return true;
};

void Solve() {
    auto CheckSubin = [&](LL N) {
        int digitSum = 0;
        while (N) {
            digitSum += N % 10;
            N /= 10;
        }
        return ~digitSum & 1;
    };
    for (LL i = 1; i <= 1000; i++) {
        if (!CheckSubin(i * N)) {
            K = i * N;
            return;
        }
    }
    for (LL i = 1; i <= 9; i++) {
        for (LL b = 10; b <= 10 * MAX; b *= 10) {
            LL k1 = (b - 1) / 9;
            LL k2 = b + 1;
            if (!CheckSubin(N * i * k1)) {
                K = N * i * k1;
                return;
            }
            if (!CheckSubin(N * i * k2)) {
                K = N * i * k2;
                return;
            }
        }
    }
    return;
};

void Output() {
    println("{}", K);
    return;
};
