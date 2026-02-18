#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti4 = tuple<int, int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
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

priority_queue<Pii> pq;
int V[MAX + 1];
int N, K, L, M, m, res;

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
    cin >> N >> K;

    for (int i : Rng(0, N)) {
        cin >> V[i];
    }
    return true;
};

void Solve() {
    ranges::sort(V | views::take(N));
    int L = N - K;
    for (int i = 1; i < L; i++) {
        pq.emplace(-V[i] + V[i - 1], i);
    }
    M = V[L - 1] - V[0];
    m = -pq.top().first;
    res = M + m;
    for (int i = L; i < N; i++) {
        while (!pq.empty() && pq.top().second <= i - L) {
            pq.pop();
        }
        pq.emplace(-V[i] + V[i - 1], i);
        M = V[i] - V[i - L + 1];
        m = -pq.top().first;
        res = min(res, M + m);
    }
};

void Output() {
    println("{}", res);
    return;
};
