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
    constexpr double EPS = 1E-4;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 10;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int c[MAX + 1];
int K, a, b, N;
double realArea, eps, dx;

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
    cin >> K;

    for (int i : Rng(0, K + 1)) {
        cin >> c[K - i];
    }

    cin >> a >> b >> N;

    return true;
};

void Solve() {
    for (int i : Rng(0, K + 1)) {
        realArea += ((double)c[i] / (i + 1)) * (pow(b, i + 1) - pow(a, i + 1));
    }
    dx = (double)(b - a) / N;
    auto F = [&](double x) {
        double s = 0;
        for (int i : Rng(0, K + 1)) {
            s += c[i] * pow(x, i);
        }
        return s;
    };
    auto Integral = [&](double e) {        
        double s = 0;
        for (int i : Rng(0, N)) {
            s += F(a + i * dx + e) * dx;
        }
        return s;
    };
    if (Integral(0) > realArea + EPS || Integral(dx) < realArea - EPS) {
        eps = -1.0;
        return;
    }
    double l = 0, r = dx;
    for (int i : Rng(0, 100)) {
        double m = (l + r) / 2;
        (Integral(m) < realArea ? l : r) = m;
    }
    eps = l;
};

void Output() {
    println("{}", eps);
    return;
};
