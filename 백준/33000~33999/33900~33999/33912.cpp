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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int A[MAX];
int N, M, order;
LL t1, t2, diff;

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
        cin >> order;
        A[--order] = i;
    }

    return true;
};

void Solve() {
    t1 = A[0];
    for (int i = 1; i < M - 1; i++) {
        diff = A[i] - A[i - 1];
        t1 += diff < 0 ? N + diff : diff;
    }
    t2 = A[N - 1];
    for (int i = N - 2; i >= M - 1; i--) {
        diff = A[i] - A[i + 1];
        t2 += diff < 0 ? N + diff : diff;
    }
};


void Output() {
    println("{}", t1 == t2 ? "EQ" : t1 < t2 ? "CW" : "CCW");
    return;
};
