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
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+6;;
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

int V;

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
    cin >> V;
    return true;
};

void Solve() {
    return;
};

void Output() {
    int p = 1, q = V;
    for (int n = sqrt(V); n >= 2; n--) {
        if (!(V % n)) {
            p = V / n;
            q = n;
            break;
        }
    }
    println("{}", p + q + 2);
    println("{} {}", 1, 2);
    for (int i = 0; i < p; i++) {
        println("1 {}", 3 + i);
    }
    for (int i = 0; i < q; i++) {
        println("2 {}", 3 + i + p);
    }
    return;
};
