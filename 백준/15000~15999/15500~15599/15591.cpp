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
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 5000;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
int BFS(int sv);
void Output();

V1<Pii> graph[MAX + 1];
bitset<MAX + 1> visChk;
queue<int> q;
int N, Q, v1, v2, k;

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
    cin >> N >> Q;

    for (int i : Rng(0, N - 1)) {
        cin >> v1 >> v2 >> k;
        --v1, --v2;
        graph[v1].emplace_back(k, v2);
        graph[v2].emplace_back(k, v1);
    }
    return true;
};

void Solve() {
    while (Q--) {
        cin >> k >> v1;
        println("{}", BFS(--v1));
    }
    return;
};

int BFS(int sv) {
    int cnt = 0;

    visChk.reset();
    visChk[sv] = true;

    q.emplace(sv);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (const auto& [nw, nv] : graph[v]) {
            if (visChk[nv] || nw < k) {
                continue;
            }
            visChk[nv] = true;
            q.emplace(nv);
            cnt++;
        }
    }
    return cnt;
};

void Output() {
    return;
};
