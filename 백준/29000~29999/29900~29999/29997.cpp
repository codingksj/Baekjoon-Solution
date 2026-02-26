#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<unordered_set>
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
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5, LIMIT = 500;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<char> groups[MAX];
string s;
int N;

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
    cin >> s >> N;

    return true;
};

void Solve() {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        groups[i % N].push_back(s[i]);
    }
    for (int i = 0; i < N; i++) {
        ranges::sort(groups[i]);
    }
    for (int i = 0; i < len; i++) {
        s[i] = groups[i % N][i / N];
    }
    return;
};

void Output() {
    println("{}", s);
    return;
};
