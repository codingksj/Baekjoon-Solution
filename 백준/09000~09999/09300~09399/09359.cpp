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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+15;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, LL n, int mu);
void Output();

V1<PLL> factors;
V1<LL> f;
LL A, B, N, res;
int TC, tc, sz;

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
    cin >> A >> B >> N;

    return true;
};

void Solve() {
    auto Factorize = [&](LL N) {
        V1<LL> factors;
        int two = countr_zero((size_t)N);
        if (two) {
            factors.push_back(2);
            N >>= two;
        }
        for (LL n = 3;;n += 2) {
            if (n * n > N) {
                break;
            }
            int cnt = 0;
            while (!(N % n)) {
                N /= n;
                cnt++;
            }
            if (cnt) {
                factors.push_back(n);
            }
        }
        if (N > 1) {
            factors.push_back(N);
        }
        return factors;
    };
    f = Factorize(N);
    sz = f.size();
    factors.clear();
    DFS(0, 1, 1);
    auto Count = [&](LL N) {
        LL cnt = 0;
        for (const auto& [n, mu] : factors) {
            cnt += (N / n) * mu;
        }
        return cnt;
    };
    res = Count(B) - Count(A - 1);
};

void DFS(int depth, LL n, int mu) {
    if (depth == sz) {
        factors.push_back({ n, mu });
        return;
    }
    LL mul = f[depth];
    if (mul <= MAX / n) {
        DFS(depth + 1, n * mul, -mu);
    }
    DFS(depth + 1, n, mu);
};

void Output() {
    println("Case #{}: {}", ++tc, res);
    return;
};
