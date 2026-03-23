#include<bits/stdc++.h>
#include<ranges>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 21;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<LL> tree;
LL a, b;
int N, M, K, Q, sz, q;

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
    cin >> N >> M >> K;

    sz = bit_ceil(ULL(N));

    tree.resize(2 * sz);

    for (int i : Rng(0, N)) {
        cin >> tree[i + sz];
    }
    return true;
};

void Solve() {
    for (int i = sz - 1;i > 0;i--) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    auto Update = [](int i, LL v) {
        tree[i += sz] = v;
        for (i >>= 1; i > 0;i >>= 1) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    };
    auto Query = [](int l, int r) {
        LL res = 0;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            (l & 1) && (res += tree[l++]);
            (r & 1) && (res += tree[--r]);
        }
        return res;
    };
    Q = M + K;
    while (Q--) {
        cin >> q >> a >> b;
        if (q == 1) {
            Update(--a, b);
        }
        else {
            println("{}", Query(--a, b));
        }
    }
};

void Output() {
    return;
};
