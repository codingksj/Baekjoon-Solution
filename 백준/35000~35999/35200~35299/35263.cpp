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
using Node = tuple<ULL, ULL, ULL, ULL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 5E+5;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
int Find(int v);
void Output();

LL fSum[MAX + 1];
bitset<MAX + 1> isPrimes, boom;
int fCnt[MAX + 1];
int pa[MAX + 2];
int A[MAX + 1];
int N, M, l, r;
double expect;

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
    iota(pa + 1, pa + MAX + 1, 1);
    isPrimes.set();
    for (int i = 2; i <= MAX; i++) {
        if (!isPrimes[i]) {
            continue;
        }
        for (int j = i; j <= MAX; j += i) {
            isPrimes[j] = false;
            fSum[j] += i;
            fCnt[j]++;
        }
        isPrimes[i] = true;
    }
    return;
};

bool Input() {
    cin >> N >> M;

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }
    return true;
};

void Solve() {
    LL sums[8] = { 0, };
    for (int i : Rng(0, M)) {
        cin >> l >> r;
        l--, r--;
        for (int v = Find(l); v <= r; v = Find(v)) {
            int n = A[v];
            sums[fCnt[n]] += fSum[n];
            boom[v] = true;
            pa[v] = Find(v + 1);
        }
    }
    for (int i : Rng(0, N)) {
        sums[1] += A[i] * !boom[i];
    }
    for (int n = 1; n <= 7; n++) {
        expect += (double)sums[n] / n;
    }
    return;
};

int Find(int v) {
    return v == pa[v] ? v : pa[v] = Find(pa[v]);
};

void Output() {
    println("{:.12f}", expect);
    return;
};
