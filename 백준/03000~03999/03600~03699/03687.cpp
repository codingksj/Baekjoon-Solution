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
using Ti4 = tuple<int, int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

string dpMn[MAX + 1];
string dpMx[MAX + 1];
string best[10] = { "", "", "1", "7", "4", "2", "0", "8" };
string mx, mn;
int TC, N;

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while(TC--) {
        Input();
        Solve();
        Output();
    }

    return 0;
}

void FastIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return;
};

void SetUp() {
    dpMn[2] = "1";
    dpMn[3] = "7";
    dpMn[4] = "4";
    dpMn[5] = "2";
    dpMn[6] = "6";
    dpMn[7] = "8";
    dpMn[8] = "10";
    auto Min = [&](const string& s1, const string& s2) {
        return s1.size() != s2.size() ? s1.size() < s2.size() ? s1 : s2 : min(s1, s2);
    };
    for (int n = 9; n <= 100; n++) {
        dpMn[n] = string(MAX, '9');
        for (int i = 2; i <= 7; i++) {
            dpMn[n] = Min(dpMn[n], dpMn[n - i] + best[i]);
        }
    }
    for (int n = 2; n <= MAX; n++) {
        dpMx[n] = n & 1 ? '7' + string((n - 3) / 2, '1') : string(n / 2, '1');
    }
    return;
};

bool Input() {
    cin >> N;

    return true;
};

void Solve() {
    mn = dpMn[N];
    mx = dpMx[N];
};

void Output() {
    println("{} {}", mn, mx);
    return;
};
