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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 50, MAX_L = 1E+3;
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

V1<Pii> gaps;
int A[MAX + 2];
int N, M, L;
int mxRange;

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
    cin >> N >> M >> L;

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }

    return true;
};

void Solve() {
    A[N] = 0;
    A[N + 1] = L;
    ranges::sort(A | views::take(N + 2));
    for (int i = 1; i < N + 2; i++) {
        gaps.push_back({ A[i - 1],  A[i]});
    }
    for (const auto& [s, e] : gaps) {
        mxRange = max(mxRange, e - s);
    }
    auto PSearch = [&](int len) {
        int cnt = 0;
        for (const auto& [s, e] : gaps) {
            cnt += (e - s - 1) / len;
        }
        return cnt <= M;
    };
    int l = 1, r = mxRange;
    while (l <= r) {
        int m = (l + r) / 2;
        if (PSearch(m)) {
            mxRange = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
};

void Output() {
    println("{}", mxRange);
    return;
};
