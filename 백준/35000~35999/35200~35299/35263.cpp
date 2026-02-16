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
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX_N = 2E+5, MAX_A = 5E+5;
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

Pii Q[MAX_N + 1];
LL sums[1 << 3];
LL factorSum[MAX_A + 1];
int spf[MAX_A + 1];
int factorCnt[MAX_A + 1];
int A[MAX_N + 1];
int N, M, st, ed;
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
    iota(spf + 1, spf + MAX_A + 1, 1);
    for (int i = 2; i <= MAX_A; i++) {
        if (spf[i] != i) {
            continue;
        }
        for (int j = i; j <= MAX_A; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
            factorSum[j] += i;
            factorCnt[j]++;
        }
    }
    return;
};

bool Input() {
    cin >> N >> M;

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }
    for (int i : Rng(0, M)) {
        cin >> st >> ed;
        Q[i] = { --st, --ed };
    }
    return true;
};

void Solve() {
    if (M == 0) {
        expect = accumulate(A, A + N, 0LL);
        return;
    }
    sort(Q, Q + M);
    tie(st, ed) = Q[0];
    for (int i = 0; i < st; i++) {
        sums[1] += A[i];
    }
    for (int i = st; i <= ed; i++) {
        int n = A[i];
        sums[factorCnt[n]] += factorSum[n];
    }
    for (int i = 1; i < M; i++) {
        const auto& [nSt, nEd] = Q[i];
        if (nSt > ed) {
            for (int j = ed + 1; j < nSt; j++) {
                sums[1] += A[j];
            }
            for (int j = nSt; j <= nEd; j++) {
                int n = A[j];
                sums[factorCnt[n]] += factorSum[n];
            }
            st = nSt, ed = nEd;
        }
        else if (nEd > ed) {
            for (int j = ed + 1; j <= nEd; j++) {
                int n = A[j];
                sums[factorCnt[n]] += factorSum[n];
            }
            ed = nEd;
        }
    }
    for (int j = ed + 1; j < N; j++) {
        sums[1] += A[j];
    }
    for (int n = 1; n <= 7; n++) {
        expect += (double)sums[n] / n;
    }
    return;
};

void Output() {
    println("{:.12f}", expect);
    return;
};
