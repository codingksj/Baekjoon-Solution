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
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 3E+6;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
int Count(int p);
void Output();

int dp[MAX + 1];
bitset<MAX + 1> isPrimes;
int P;

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
    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = dp[4] = 0;
    dp[2] = dp[3] = 1;
    isPrimes.set();

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrimes[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrimes[j] = false;
            }
        }
    }
    return;
};

bool Input() {
    cin >> P;

    return true;
};

void Solve() {
    Count(P);
    return;
};

int Count(int p) {
    if (dp[p] != -1) {
        return dp[p];
    }
    if (!(p & 1)) {
        return dp[p] = 0;
    }
    int val = 0;
    for (int n = p / 2; n >= 2; n--) {
        int m = p - n - 1;
        if (isPrimes[m] && isPrimes[n]) {
            val = Count(m) + Count(n) + 1;
            break;
        }
    }
    return dp[p] = val;
}

void Output() {
    println("{}", dp[P]);
    return;
};
