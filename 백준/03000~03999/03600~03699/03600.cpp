#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Bitset = array<ULL, 80>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr double EPS = 1E-4;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 5'000, SHIFT = 1 << 6;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

set<Bitset> combs;
bitset<MAX + 1> S, T, mask(ULLONG_MAX);
string s, t;
int N, repeat;
bool canMake;

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
    cin >> t >> s;

    return true;
};

void Solve() {
    N = s.size();
    repeat = (N + SHIFT - 1) / SHIFT;
    S = bitset<MAX + 1>(s);
    T = bitset<MAX + 1>(t);

    auto Convert = [&](bitset<MAX + 1> b) {
        Bitset A = Bitset();
        for (int i = 0; i < repeat; i++) {
            A[i] = (b & mask).to_ullong();
            b >>= SHIFT;
        }
        return A;
    };
    for (int i : Rng(0, N)) {
        combs.insert(Convert(S ^ T));
        bool b = S[N - 1];
        S <<= 1;
        S[0] = b;
        S[N] = 0;
    }
    for (int i : Rng(0, N)) {
        if (combs.count(Convert(S))) {
            canMake = true;
            return;
        }
        bool b = S[N - 1];
        S <<= 1;
        S[0] = b;
        S[N] = 0;
    }
};

void Output() {
    println("{}", canMake ? "Yes" : "No");
    return;
};
