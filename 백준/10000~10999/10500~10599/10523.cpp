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
int N, P;
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
    cin >> N >> P;

    for (int i : Rng(0, N)) {
        auto& [x, y] = dots[i];
        cin >> x >> y;
    }

    return true;
};

void Solve() {
    int mn = (N * P + 99) / 100;
    if (N <= 2) {
        isExist = true;
        return;
    }
    if (N <= LIMIT) {
        for (int i = 0; i < N; i++) {
            const auto& [x1, y1] = dots[i];
            for (int j = i + 1; j < N; j++) {
                const auto& [x2, y2] = dots[j];
                int cnt = 0;
                for (int k = 0; k < N; k++) {
                    const auto& [x, y] = dots[k];
                    cnt += (y - y1) * (x2 - x1) == (y2 - y1) * (x - x1);
                }
                if (cnt >= mn) {
                    isExist = true;
                    return;
                }
            }
        }
    }
    else {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, N - 1);
        for (int t : Rng(0, 100)) {
            int i = dis(gen);
            int j = dis(gen);
            while (i == j) {
                j = dis(gen);
            }
            const auto& [x1, y1] = dots[i];
            const auto& [x2, y2] = dots[j];
            int cnt = 0;
            for (int k = 0; k < N; k++) {
                const auto& [x, y] = dots[k];
                cnt += (y - y1) * (x2 - x1) == (y2 - y1) * (x - x1);
            }
            if (cnt >= mn) {
                isExist = true;
                return;
            }
        }
    }
};

void Output() {
    println("{}", isExist ? "possible" : "impossible");
    return;
};
