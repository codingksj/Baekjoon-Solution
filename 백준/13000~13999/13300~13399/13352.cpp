#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<random>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5, LIMIT = 500;
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

PLL dots[MAX];
PLL others[MAX];
int N, otherCnt;
bool isExist;

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

    for (int i : Rng(0, N)) {
        auto& [x, y] = dots[i];
        cin >> x >> y;
    }

    return true;
};

void Solve() {
    if (N <= 4) {
        isExist = true;
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, N - 1);

    auto Chk1 = [&](int i, int j) {
        const auto& [x1, y1] = dots[i];
        const auto& [x2, y2] = dots[j];
        otherCnt = 0;
        for (int k = 0; k < N; k++) {
            const auto& [x, y] = dots[k];
            if ((y - y1) * (x2 - x1) != (y2 - y1) * (x - x1)) {
                others[otherCnt++] = dots[k];
            }
        }
        return otherCnt <= 2;
    };
    auto Chk2 = [&]() {
        const auto& [x1, y1] = others[0];
        const auto& [x2, y2] = others[1];
        for (int k = 2; k < otherCnt; k++) {
            const auto& [x, y] = others[k];
            if ((y - y1) * (x2 - x1) != (y2 - y1) * (x - x1)) {
                return false;
            }
        }
        return true;
    };
    for (int t : Rng(0, 100)) {
        int i = dis(gen);
        int j = dis(gen);
        while (i == j) {
            j = dis(gen);
        }
        if (Chk1(i, j) || Chk2()) {
            isExist = true;
            return;
        }
    }
};

void Output() {
    println("{}", isExist ? "success" : "failure");
    return;
};
