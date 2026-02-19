#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50000;
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
int TC, strType;

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
    return;
};

bool Input() {
    cin >> s;

    return true;
};

void Solve() {
    int sz = s.size();

    strType = 0;

    auto isPal = [&](const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    };

    for (int l = 0, r = sz - 1; l < r; l++, r--) {
        char a = s[l];
        char b = s[r];
        if (a != b) {
            strType = 1 + !(isPal(s, l + 1, r) || isPal(s, l, r - 1));
            return;
        }
    }
};

void Output() {
    println("{}", strType);
    return;
};
