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
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 60, LIMIT = 500;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

Pii A[3 * MAX];
int citys[3][MAX];
int K;

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

    for (int i : Rng(0, 3 * K)) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    return K;
};

void Solve() {
    random_device rd;
    mt19937 gen(rd());

    auto Check = [&](int city) {
        int sum = 0;
        for (int i = K * city; i < K * (city + 1); i++) {
            sum += A[i].first;
        }
        return sum > LIMIT * K;
    };
    auto Fill = [&](int city, int idx) {
        for (int i = 0; i < K; i++) {
            citys[city][i] = A[K * idx + i].second;
        }
    };
    ranges::sort(A, A + 3 * K, greater<>());
    for (int test : Rng(0, 100000)) {
        shuffle(A, A + 2 * K, gen);
        bool chk0 = Check(0);
        bool chk1 = Check(1);
        bool chk2 = Check(2);
        if (chk0 && chk1) {
            Fill(0, 0);
            Fill(1, 1);
            Fill(2, 2);
            return;
        }
    }

    return;
};

void Output() {
    for (int c : Rng(0, 3)) {
        for (int i : Rng(0, K)) {
            println("{}", citys[c][i]);
        }
    }
    return;
};
