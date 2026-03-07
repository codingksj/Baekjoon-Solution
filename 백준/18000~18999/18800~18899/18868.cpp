#include<bits/stdc++.h>
#include<ranges>
#include<print>

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
    constexpr Pii DT4[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX_M = 100, MAX_N = 1E+4;
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

Pii space[MAX_M][MAX_N];
int N, M, cnt;

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
    cin >> M >> N;

    return true;
};

void Solve() {
    auto Compress = [&](int idx) {
        auto sub = space[idx] | views::take(N);
        int cnt = 0;
        ranges::sort(sub);
        int target = sub[0].first;
        for (auto& [a, i] : sub) {
            if (a == target) {
                a = cnt;
            }
            else {
                target = a;
                a = ++cnt;
            }
        } 
        ranges::sort(sub, [&](const Pii& p1, const Pii& p2) { return p1.second < p2.second; });
    };
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j].first;
            space[i][j].second = j;
        }
        Compress(i);
    }
    auto IsSame = [&](int t1, int t2) {
        for (int i = 0; i < N; i++) {
            if (space[t1][i].first != space[t2][i].first) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            IsSame(i, j) && cnt++;
        }
    }
};

void Output() {
    println("{}", cnt);
    return;
};
