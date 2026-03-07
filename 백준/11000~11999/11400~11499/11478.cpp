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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 500'500;
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

int trie[MAX][ALPHABETS];
string s;
int cnt;

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
    cin >> s;

    return true;
};

void Solve() {
    int sz = s.size();
    auto Insert = [&](int st) {
        int cur = 0;
        for (int i = st; i < sz; i++) {
            int idx = s[i] - '0';
            if (!trie[cur][idx]) {
                trie[cur][idx] = ++cnt;
            }
            cur = trie[cur][idx];
        }
    };
    for (int i = 0; i < sz; i++) {
        Insert(i);
    }
};

void Output() {
    println("{}", cnt);
    return;
};
