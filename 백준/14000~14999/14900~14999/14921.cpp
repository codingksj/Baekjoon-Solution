#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<random>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5;
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

int A[MAX];
int N, best = 2 * INF;

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

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }

    return true;
};

void Solve() {
    ranges::sort(A | views::take(N));
    best = A[0] + A[N - 1];
    for (int l = 0, r = N - 1; l < r;) {
        int sum = A[l] + A[r];
        if (abs(sum) < abs(best)) {
            best = sum;
        }
        if (sum == 0) {
            return;
        }
        sum < 0 ? l++ : r--;
    }
};

void Output() {
    println("{}", best);
    return;
};
