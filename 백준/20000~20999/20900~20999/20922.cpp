#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Bitset = array<ULL, 80>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr double EPS = 1E-4;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 200'000;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int counts[MAX / 2 + 1];
int A[MAX + 1];
int N, K, mxLen;

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
    cin >> N >> K;

    for (int i : Rng(0, N)) {
        cin >> A[i];
    }
    return true;
};

void Solve() {
    if (N == 1) {
        mxLen = 1;
        return;
    }
    for (int l = 0, r = 0; r < N; r++) {
        counts[A[r]]++;
        while (counts[A[r]] > K) {
            counts[A[l]]--;
            l++;
        }
        mxLen = max(mxLen, r - l + 1);
    }
};

void Output() {
    println("{}", mxLen);
    return;
};
