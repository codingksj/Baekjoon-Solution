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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 15;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int dists[1 << MAX];
int a, t1, t2;
int N, M, bit, mnOper = INF;

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
    cin >> N >> M;

    for (int i : Rng(0, N)) {
        cin >> bit;
        a = (a << 1) | bit;
    }
    for (int i : Rng(0, M)) {
        cin >> bit;
        if (i & 1) {
            t1 = (t1 << bit) | ((1 << bit) - 1); 
            t2 <<= bit;                           
        }
        else {
            t2 = (t2 << bit) | ((1 << bit) - 1); 
            t1 <<= bit;                           
        }
    }

    return true;
};

void Solve() {
    for (int t : {t1, t2}) {
        memset(dists, -1, sizeof(dists));
        queue<Pii> q;
        q.push({ a, 0 });
        dists[a] = 0;
        while (!q.empty()) {
            auto [n, s] = q.front(); q.pop();
            if (n == t) {
                mnOper = min(mnOper, s);
                break;
            }
            for (int i = 0; i < N - 1; i++) {
                int b1 = (n >> i) & 1;
                int b2 = (n >> (i + 1)) & 1;
                int nn = n ^ ((1 << i) | (1 << (i + 1)));
                if (b1 != b2 && dists[nn] == -1) {
                    dists[nn] = dists[n] + 1;
                    q.push({ nn, dists[nn] });
                }
            }
        }
    }
    return;
};

void Output() {
    println("{}", mnOper);
    return;
};
