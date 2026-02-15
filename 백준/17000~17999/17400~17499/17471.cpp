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
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 10;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, int start, int used, int maxPick);
int CalcDiff(int team, int maxPick);
int CheckConnect(int v, int group, int count);
void Output();

V1<int> graph[MAX + 1];
queue<int> q;
int P[MAX + 1];
int N, adj, v, mnDiff = INF;

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
        cin >> P[i];
    }
    for (int i : Rng(0, N)) {
        cin >> adj;
        while (adj--) {
            cin >> v;
            --v;
            graph[i].push_back(v);
            graph[v].push_back(i);
        }
    }
    return true;
};

void Solve() {
    for (int i : Rng(1, N / 2 + 1)) {
        DFS(0, 0, 0, i);
    }
    return;
};

void DFS(int depth, int start, int used, int maxPick) {
    if (depth == maxPick) {
        mnDiff = min(mnDiff, CalcDiff(used, maxPick));
        return;
    }
    for (int i = start; i < N; i++) {
        if (used & (1 << i)) {
            continue;
        }
        DFS(depth + 1, i + 1, used | 1 << i, maxPick);
    }
};

int CalcDiff(int team, int maxPick) {
    int t1 = -1, t2 = -1;
    for (int i = 0; i < N; i++) {
        if (t1 == -1 && (team & (1 << i))) {
            t1 = i;
        }
        if (t2 == -1 && !(team & (1 << i))) {
            t2 = i;
        }
    }
    int sum1 = CheckConnect(t1, team, maxPick);
    if (!sum1) {
        return INF;
    }
    int sum2 = CheckConnect(t2, ~team, N - maxPick);
    if (!sum2) {
        return INF;
    }
    return abs(sum1 - sum2);
};

int CheckConnect(int v, int group, int count) {
    int visChk = 1 << v;
    int groupCnt = 1;
    int sum = P[v];

    q.push(v);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int nv : graph[v]) {
            int b = 1 << nv;
            if ((group & b) && !(visChk & b)) {
                visChk |= b;
                groupCnt++;
                sum += P[nv];
                q.push(nv);
            }
        }
    }
    return groupCnt == count ? sum : 0;
}

void Output() {
    println("{}", mnDiff == INF ? -1 : mnDiff);
    return;
};
