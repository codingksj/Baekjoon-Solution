#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<random>

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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 600;
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
int N, mnDelta = INT_MAX;

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
    for (int left = 0; left < N; left++) {
        for (int right = N - 1; right >= 0 && right - left >= 3; right--) {
            int target = A[left] + A[right];
            int delta = 0;
            for (int l = left + 1, r = right - 1; l < r; delta < 0 ? l++ : r--) {
                int snowMan = A[l] + A[r];
                delta = snowMan - target;
                mnDelta = min(mnDelta, abs(delta));
                if (delta == 0) {
                    return;
                }
            }
        }
    }
};

void Output() {
    println("{}", mnDelta);
    return;
};
