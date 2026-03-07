#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 10;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, int i);
void Output();

int A[MAX];
int B[MAX];
int N, M;

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
    cin >> N >> M;

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }
    return true;
};

void Solve() {
    ranges::sort(A | views::take(N));
    DFS(0, 0);
};

void DFS(int depth, int idx) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            print("{}{}", B[i], SEPS[i == M - 1]);
        }
        return;
    }
    int prv = 0;
    for (int i = idx; i < N; i++) {
        if (A[i] == prv) {
            continue;
        }
        prv = A[i];
        B[depth] = A[i];
        DFS(depth + 1, i + 1);
    }
};

void Output() {
    return;
};
