#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr double EPS = 1E-4;
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

Pii res[DIGITS];
V1<int> nIdx, opIdx;
int picks[DIGITS];
bool adj[DIGITS][DIGITS];
char expr[DIGITS];
int N, M;
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
    for (int n : {0, 2, 4, 6, 8}) {
        if (n >= 3) {
            adj[n][n - 3] = adj[n - 3][n] = true;
        }
        if (n < 6) {
            adj[n][n + 3] = adj[n + 3][n] = true;
        }
        if (n == 2 || n == 4 || n == 8) {
            adj[n - 1][n] = adj[n][n - 1] = true;
        }
        if (n == 0 || n == 4 || n == 6) {
            adj[n][n + 1] = adj[n + 1][n] = true;
        }
    }
    return;
};

bool Input() {
    cin >> N >> M;

    for (int i : Rng(0, 9)) {
        cin >> expr[i];
        (i & 1 ? opIdx : nIdx).push_back(i);
    }

    return true;
};

void Solve() {
    auto Chk1 = [&]() {
        for (int i = 0; i < 2 * M - 1; i++) {
            if (i & 1) {
                int& pick = picks[i];
                pick = opIdx[i / 2];
                res[i] = { pick / 3, pick % 3 };
                if (!adj[picks[i]][picks[i - 1]]) {
                    return false;
                }
            }
            else {
                int& pick = picks[i];
                pick = nIdx[i / 2];
                res[i] = { pick / 3, pick % 3 };
            }
        }
        return true;
    };
    auto Chk2 = [&]() {
        for (int i = 0; i < M - 1; i++) {
            int idx = picks[2 * (i + 1)];
            int op = picks[2 * i + 1];
            if (!adj[idx][op]) {
                return false;
            }
        }
        return true;
    };
    auto Chk3 = [&]() {
        int sum = expr[picks[0]] - '0';
        for (int i = 0; i < M - 1; i++) {
            int n = expr[picks[2 * (i + 1)]] - '0';
            sum += expr[picks[2 * i + 1]] == '+' ? n : -n;
        }
        return sum == N;
    };
    do {
        do {
            if (Chk1() && Chk2() && Chk3()) {
                isExist = true;
                return;
            }
        } while (ranges::next_permutation(opIdx).found);
    }while (ranges::next_permutation(nIdx).found);
};

void Output() {
    println("{}", (int)isExist);
    if (isExist) {
        for (int i = 0; i < 2 * M - 1; i++) {
            const auto& [r, c] = res[i];
            println("{} {}", r, c);
        }
    }
    return;
};
