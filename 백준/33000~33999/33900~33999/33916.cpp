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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 5E+3;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<int> primes;
bool isPrimes[MAX + 1];
int TC;
int n1, n2, r1, r2;
bool isCoprime;

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
    memset(isPrimes, true, sizeof(isPrimes));
    primes.push_back(2);
    for (int n = 4; n <= MAX; n += 2) {
        isPrimes[n] = false;
    }
    for (int n = 3; n * n <= MAX; n += 2) {
        if (isPrimes[n]) {
            for (int p = n * n; p <= MAX; p += 2 * n) {
                isPrimes[p] = false;
            }
        }
    }
    for (int p = 3; p <= MAX; p += 2) {
        if (isPrimes[p]) {
            primes.push_back(p);
        }
    }
    return;
};

bool Input() {
    cin >> n1 >> r1 >> n2 >> r2;

    return true;
};

void Solve() {
    if (n1 > n2) {
        swap(n1, n2);
        swap(r1, r2);
    }
    auto Count = [](int p, int N) {
        int cnt = 0;
        for (int n = p;;n *= p) {
            cnt += N / n;
            if (n > N / p) {
                break;
            }
        }
        return cnt;
    };
    auto CheckCoprime = [&Count]() {
        for (int p : primes) {
            if (p > n2) {
                break;
            }
            int cnt1 = Count(p, n1) - Count(p, r1) - Count(p, n1 - r1);
            int cnt2 = Count(p, n2) - Count(p, r2) - Count(p, n2 - r2);
            if (cnt1 && cnt2) {
                return false;
            }
        }
        return true;
    };
    isCoprime = CheckCoprime();
};

void Output() {
    println("{}", (int)isCoprime);
    return;
};
