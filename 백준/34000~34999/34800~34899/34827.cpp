#include<bits/stdc++.h>
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
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+6;
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
int N, X, Y, used;

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
    cin >> N >> s;

    return true;
};

void Solve() {
    used |= 1 << (s[0] - 'A');
    for (int i = 1; i < N; i++) {
        s[i - 1] < s[i] ? X++ : Y++;
        used |= 1 << (s[i] - 'A');
    }
    if (abs(X - Y) <= 1) {
        return;
    }
    char first = 'A', last = 'Z';
    int inc;
    bool isFirst = true;
    if (X > Y) {
        inc = -1;
        swap(first, last);
        swap(X, Y);
    }
    else {
        inc = 1;
    }
    for (char c = s.back(); c != last + inc; c += inc) {
        int idx = (c - 'A');
        if (!(used & (1 << idx))) {
            s += c;
            used |= (1 << idx);
            X++;
        }
        if (abs(X - Y) <= 1) {
            return;
        }
    }
    for (char c = first; c != last - inc; c += inc) {
        int idx = (c - 'A');
        if (!(used & (1 << idx))) {
            s += c;
            used |= (1 << idx);
            if (isFirst) {
                Y++;
                isFirst = false;
            }
            else {
                X++;
            }
        }
        if (abs(X - Y) <= 1) {
            return;
        }
    }
};

void Output() {
    println("{}", s.size());
    println("{}", s);
    return;
};
