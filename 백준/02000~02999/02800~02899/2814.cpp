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
using Ti4 = tuple<int, int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, SQRT_MAX = 32'000, MAX = 1E+9, MAX_P = 31;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int idx, int P, LL n, int mu);
void Output();

V1<PLL> valids;
V1<int> primes;
bitset<SQRT_MAX + 1> isPrimes;
bool sieve[MAX / MAX_P + 1];
LL N, P, K, sz;

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
    isPrimes.set();
    for (int n = 4; n <= SQRT_MAX; n += 2) {
        isPrimes[n] = false;
    }
    for (int i = 3; i <= SQRT_MAX; i += 2) {
        if (isPrimes[i]) {
            for (int j = i * i; j <= SQRT_MAX; j += 2 * i) {
                isPrimes[j] = false;
            }
        }
    }
    for (int i = 3; i <= SQRT_MAX; i += 2) {
        if (isPrimes[i]) {
            primes.push_back(i);
        }
    }
    sz = primes.size();
    return;
};

bool Input() {
    cin >> N >> P;

    return true;
};

void Solve() {
    if (N == 1) {
        K = P;
        return;
    }
    if (P * P > MAX || N * P > MAX) {
        return;
    }
    if (P == 2) {
        K = 2 * N;
        return;
    }
    if (P < MAX_P) {
        DFS(0, P, 1, 1);
        ranges::sort(valids);
        auto Count = [&](int P, int m) {
            LL count = (m + 1) / 2;
            for (const auto& [n, mu] : valids) {
                if (n > m) {
                    break;
                }
                count += mu * ((m / n) + 1) / 2;
            }
            return count;
        };
        LL res = 0;
        int l = 1, r = MAX / P;
        while (l <= r) {
            int m = (l + r) / 2;
            if (Count(P, m) >= N) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        K = P * res;
        return;
    }
    memset(sieve, 1, sizeof(sieve));
    int M = MAX / P;
    for (int n = 2; n <= M; n += 2) {
        sieve[n] = false;
    }
    int pos = ranges::lower_bound(primes, P) - primes.begin();
    for (int i = 0; i < pos; i++) {
        int p = primes[i];
        sieve[p] = false;
        for (int n = p * p; n <= M; n += 2 * p) {
            sieve[n] = false;
        }
    }
    for (int n = 1, cnt = 0; n <= M; n++) {
        if (sieve[n]) {
            cnt++;
        }
        if (cnt == N) {
            K = n * P;
            return;
        }
    }
    return;
};

void DFS(int idx, int P, LL n, int mu) {
    if (idx >= sz || primes[idx] >= P) {
        return;
    }
    for (int i = idx; i < sz && primes[i] < P; i++) {
        LL nn = n * primes[i];
        if (nn > MAX) {
            break;
        }
        valids.push_back({nn, -mu});
        DFS(i + 1, P, nn, -mu);
    }
}

void Output() {
    println("{}", K);
    return;
};
