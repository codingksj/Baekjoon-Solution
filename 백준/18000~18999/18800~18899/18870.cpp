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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+6, MAX_N = 1E+9;
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

Pii A[MAX];
int N, cnt;

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
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    return true;
};

void Solve() {
    ranges::sort(A | views::take(N));
    int target = A[0].first;
    for (int i = 0; i < N; i++) {
        if (A[i].first == target) {
            A[i].first = cnt;
        }
        else {
            target = A[i].first;
            A[i].first = ++cnt;
        }
    }
    ranges::sort(A | views::take(N), [&](const Pii& p1, const Pii& p2) {return p1.second < p2.second; });
};

void Output() {
    for (int i = 0; i < N; i++) {
        print("{}{}", A[i].first, SEPS[i == N - 1]);
    }
    return;
};
