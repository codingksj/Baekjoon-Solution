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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5;
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

string X, cmd;
int TC, N, l, r;
bool isError, isRev;

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
    cin >> cmd >> N >> X;

    return true;
};

void Solve() {
    isError = false;
    isRev = false;
    int st = 0, ed = N - 1;
    for (char ch : cmd) {
        if (ch == 'R') {
            isRev = !isRev;
        }
        else {
            if (st > ed) {
                isError = true;
                return;
            }
            isRev ? ed-- : st++;
        }
    }
    int L = X.size();
    l = 1, r = L - 2;
    for (int skip = 0; skip < st && l < L; l++) {
        if (X[l] == ',') {
            skip++;
        }
    }
    for (int skip = 0; skip < N - 1 - ed && r >= 0; r--) {
        if (X[r] == ',') {
            skip++;
        }
    }
};

void Output() {
    if (isError) {
        println("error");
    }
    else {
        print("[");
        int n = 0;
        if (isRev) {
            int mul = 1;
            for (int i = r; i >= l; i--) {
                char ch = X[i];
                if (isdigit(ch)) {
                    n += mul * (ch - '0');
                    mul *= 10;
                }
                else {
                    print("{},", n);
                    n = 0;
                    mul = 1;
                }
            }
            if (n) {
                print("{}", n);
            }
        }
        else {
            for (int i = l; i <= r; i++) {
                print("{}", X[i]);
            }
        }
        println("]");
    }
    return;
};
