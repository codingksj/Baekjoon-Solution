#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
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
int N, Q, q, a, b, sz;

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

    sz = bit_ceil((size_t)N);
    tree.assign(2 * sz, INF);

    for (int i : Rng(0, N)) {
        cin >> tree[sz + i];
    }
    for (int i = sz - 1; i > 0; i--) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }
    cin >> Q;

    return true;
};

void Solve() {
    auto Update = [&](int i, int val) {
        tree[i += sz] = val;
        for (i >>= 1; i >= 1; i >>= 1) {
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
        }
    };
    auto Query = [&](int l, int r) {
        int res = INF;
        for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res = min(res, tree[l++]);
            }
            if (~r & 1) {
                res = min(res, tree[r--]);
            }
        }
        return res;
    };
    while (Q--) {
        cin >> q >> a >> b;
        if (q == 1) {
            Update(a - 1, b);
        }
        else {
            println("{}", Query(--a, --b));
        }
    }
};

void Output() {
    return;
};
