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
    constexpr string_view target = "long";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MAX = 1501, MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
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

map<Node, int> hashS;
set<Node> hashT;
string s, t;
ULL pows[1 << 3] = {1ULL, };
int N, M, mxL;

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
    for (int i = 1; i <= 6; i++) {
        pows[i] = pows[i - 1] * MAX;
    }
    return;
};

bool Input() {
    cin >> s >> t;

    return true;
};

void Solve() {
    N = s.length();
    M = t.length();
    for (int i = 0; i < N; i++) {
        ULL v[4] = { 0, };
        for (int j = i; j < N; j++) {
            int alpha = s[j] - 'a';
            int idx = (alpha / MOD);
            int exp = alpha % MOD;
            v[idx] += pows[exp];
            Node node = { v[0], v[1], v[2], v[3] };
            hashS.insert({ node, j - i + 1 });
        }
    }
    for (int i = 0; i < M; i++) {
        ULL v[4] = { 0, };
        for (int j = i; j < M; j++) {
            int alpha = t[j] - 'a';
            int idx = (alpha / MOD);
            int exp = alpha % MOD;
            v[idx] += pows[exp];
            Node node = { v[0], v[1], v[2], v[3] };
            if (hashS.count(node)) {
                mxL = max(mxL, j - i + 1);
            }
        }
    }
    return;
};

void Output() {
    println("{}", mxL);
    return;
};
