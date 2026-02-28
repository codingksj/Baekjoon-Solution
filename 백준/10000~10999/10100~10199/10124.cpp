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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 5E+5, LIMIT = 300, SAMPLE = 30;
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

V1<int> pos[MAX + 1];
int counts[MAX + 2];
int A[MAX + 1];
int used[MAX + 1];
int N, Q, a, b, q;

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

    for (int i : Rng(0, N)) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }

    return true;
};

void Solve() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis;

    memset(used, -1, sizeof(used));

    auto BF = [&](int a, int b) {
        int mode = 0;
        int len = b - a + 1;
        int half = len / 2;
        int i = a;
        for (; i <= b; i++) {
            int val = A[i];
            if (++counts[val] > half) {
                mode = val;
                break;
            }
        }
        for (; i >= a; i--) {
            counts[A[i]] = 0;
        }
        return mode;
    };
    auto GetCount = [&](int val, int l, int r) {
        return ranges::upper_bound(pos[val], r) - ranges::lower_bound(pos[val], l);
    };
    auto RandomCheck = [&](int a, int b, int q) {
        dis.param(uniform_int_distribution<int>::param_type{ a, b });
        int half = (b - a + 1) / 2;
        for (int t = 0, s = 0; t < 3 * SAMPLE && s < SAMPLE; t++) {
            int idx = dis(gen);
            int cand = A[idx];
            if (used[cand] == q) {
                continue;
            }
            used[cand] = q;
            s++;
            if (GetCount(cand, a, b) > half) {
                return cand;
            }
        }
        return 0;
    };
    for (int q = 0; q < Q; q++) {
        cin >> a >> b;
        --a, --b;
        int len = b - a + 1;
        int head = (len <= LIMIT) ? BF(a, b) : RandomCheck(a, b, q);
        println("{}", head);
    }
};

void Output() {
    return;
};
