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
using Pot = int[3];
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+6;
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

bitset<MAX + 1> visChk;
int N, a, b, c, cnt;

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

    return true;
};

void Solve() {
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        bool exist = visChk[a] | visChk[b] | visChk[c];
        cnt += !exist;
        visChk[a] = visChk[b] = visChk[c] = true;
    }
    return;
};

void Output() {
    println("{}", cnt);
    return;
};
