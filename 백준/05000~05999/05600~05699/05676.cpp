#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using PULL = pair<ULL, ULL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n", RES = "-0+";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5;
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

V1<int> tree;
string res;
int N, Q, x, sz;
char cmd;

int main() {
    FastIO();
    SetUp();

    while (Input()) {
        Solve();
        Output();
    };

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
    return (bool)(cin >> N >> Q);
};

void Solve() {
    sz = bit_ceil((ULL)N);
    tree.resize(2 * sz);
    res.clear();
    for (int i : Rng(0, N)) {
        cin >> x;
        tree[i + sz] = (!x ? 0 : (x > 0 ? 1 : -1));
    }
    for (int i = sz - 1; i > 0; i--) {
        tree[i] = tree[i << 1] * tree[i << 1 | 1];
    }
    auto Update = [&](int i, int x) {
        int v = (!x ? 0 : (x > 0 ? 1 : -1));
        for (tree[i += sz] = v, i >>= 1; i >= 1; i >>= 1) {
            tree[i] = tree[i << 1] * tree[i << 1 | 1];
        }
    };
    auto Query = [&](int l, int r) {
        int res = 1;
        for (l += sz, r+=sz; l <= r; l >>= 1, r >>= 1) {
            (l & 1) && (res *= tree[l++]);
            (~r & 1) && (res *= tree[r--]);
            if (!res) {
                return 1;
            }
        }
        return (res > 0) << 1;
    };
    while (Q--) {
        cin >> cmd;
        if (cmd == 'C') {
            int i, x;
            cin >> i >> x;
            Update(--i, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            res += RES[Query(--l, --r)];
        }
    }
    return;
};

void Output() {
    println("{}", res);
    return;
};
