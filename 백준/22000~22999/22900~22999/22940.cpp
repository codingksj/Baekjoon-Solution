#include <bits/stdc++.h>
#include <ranges>
#include <print>

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
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 10;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V2<double> A;
double B[MAX];
int X[MAX]; 
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
    cin >> N;

    A.assign(N, V1<double>(N));

    for (int r : Rng(0, N)) {
        for (int c : Rng(0, N)) {
            cin >> A[r][c];
        }
        cin >> B[r];
    }

    return true;
};

void Solve() {
    auto RowSwap = [](int r) {
        for (int nr = r + 1; nr < N; nr++) {
            if (A[nr][r]) {
                swap(A[r], A[nr]);
                swap(B[r], B[nr]);
                return;
            }
        }
    };
    auto GaussElim = [&]() {
        for (int r : Rng(0, N)) {
            if (!A[r][r]) {
                RowSwap(r);
            }
            double pivot = A[r][r];
            if (!pivot) {
                continue;
            }
            for (int nr = r + 1; nr < N; nr++) {
                double k = A[nr][r] / pivot; 
                B[nr] -= k * B[r];
                for (int c = r; c < N; c++) {
                    A[nr][c] -= k * A[r][c];
                }
            }
        }
    };
    auto BackSub = [&]() {
        for (int r : Rng(0, N) | Rev) {
            double k = A[r][r];
            if (!k) {
                continue;
            }
            double res = B[r];
            for (int c = r + 1; c < N; c++) {
                res -= A[r][c] * X[c];
            }
            X[r] = round(res / k);
        }
    };
    GaussElim();
    BackSub();
};

void Output() {
    for (int i : Rng(0, N)) {
        print("{}{}", X[i], SEPS[i == N - 1]);
    }
};
