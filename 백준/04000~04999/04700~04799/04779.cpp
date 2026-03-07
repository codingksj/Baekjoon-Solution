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
void Cantor(int depth, int size);
void Output();

int N;

int main() {
    FastIO();
    SetUp();

    while (Input()) {
        Solve();
        Output();
    };

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
    return (bool)(cin >> N);
};

void Solve() {
    auto Pow = [&](int b, int e) {
        int res = 1;
        while (e--) {
            res *= b;
        }
        return res;
    };
    Cantor(0, Pow(3, N));
};

void Cantor(int depth, int size) {
    if (depth == N) {
        print("-");
        return;
    }
    Cantor(depth + 1, size / 3);
    for (int i = 0; i < size / 3; i++) {
        print(" ");
    }
    Cantor(depth + 1, size / 3);
};

void Output() {
    println("");
    return;
};
