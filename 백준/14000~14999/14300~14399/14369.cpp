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
    constexpr string_view SEPS = " \n", EVEN = "ZWUXG", ODD = "OHFSI";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+8;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

string digits[DIGITS] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", 
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
string s, res;
int TC, N, tc;
int counts[ALPHABETS];

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while (TC--) {
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
    memset(counts, 0, sizeof(counts));
    res.clear();
    for (const char ch : s) {
        counts[ch - 'A']++;
    }
    for (int i = 0; i < 5; i++) {
        while (counts[EVEN[i] - 'A']) {
            for (const char ch : digits[i * 2]) {
                counts[ch - 'A']--;
            }
            res += ('0' + i * 2);
        }
    }
    for (int i = 0; i < 5; i++) {
        while (counts[ODD[i] - 'A']) {
            for (const char ch : digits[i * 2 + 1]) {
                counts[ch - 'A']--;
            }
            res += ('1' + i * 2);
        }
    }
    ranges::sort(res);
    return;
};

void Output() {
    println("Case #{}: {}", ++tc, res);
    return;
};
