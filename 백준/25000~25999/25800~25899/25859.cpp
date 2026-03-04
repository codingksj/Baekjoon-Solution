#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>
#include<random>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n", KOREA = "KOREA";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
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

string s;
int counts[ALPHABETS];

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
    for (const char ch : s) {
        counts[ch - 'a']++;
    }
    auto Cmp = [&](const char& ch1, const char& ch2) {
        return (counts[ch1 - 'a'] != counts[ch2 - 'a']) ? counts[ch1 - 'a'] > counts[ch2 - 'a'] : ch1 < ch2;
    };
    ranges::sort(s, Cmp);
};

void Output() {
    println("{}", s);
    return;
};
