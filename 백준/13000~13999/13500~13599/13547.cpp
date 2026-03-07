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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5, MAX_A = 1E+6, SHIFT = 9, BUCKET = 1 << SHIFT, SIZE = MAX / BUCKET + 1;
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

bitset<MAX> table[bit_width(SIZE) + 1][SIZE];
int A[MAX];
int idxOf[MAX_A];
int used[MAX];
int N, M, Q, a, l, r, cnt;

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
    memset(idxOf, -1, sizeof(idxOf));
    return;
};

bool Input() {
    cin >> N;

    for (int i : Rng(0, N)) {
        cin >> a;
        A[i] = a;
        if (idxOf[a] == -1) {
            idxOf[a] = cnt++;
        }
    }
    cin >> Q;

    return true;
};

void Solve() {
    for (int i : Rng(0, N)) {
        int& a = A[i];
        a = idxOf[a];
        table[0][i >> SHIFT][a] = true;
    }
    for (int k = 1; k <= (int)bit_width(SIZE); k++) {
        for (int i = 0; i + (1 << k) <= SIZE; i++) {
            table[k][i] = table[k - 1][i] | table[k - 1][i + (1 << (k - 1))];
        }
    }
    bitset<MAX> res;
    auto Query = [&](int l, int r, int q) {
        int L = (l + BUCKET - 1) >> SHIFT;
        int R = (r + 1) >> SHIFT;
        if (L < R) {
            int k = bit_width(ULL(R - L)) - 1;
            res = table[k][L] | table[k][R - (1 << k)];
            for (int i = l; i < (L << SHIFT); i++) {
                res[A[i]] = true;
            }
            for (int i = (R << SHIFT); i <= r; i++) {
                res[A[i]] = true;
            }
            return (ULL)res.count();
        }
        else {
            ULL cnt = 0;
            for (int i = l; i <= r; i++) {
                if (used[A[i]] != q) {
                    used[A[i]] = q;
                    cnt++;
                }
            }
            return cnt;
        }
    };
    for (int q = 1; q <= Q; q++) {
        cin >> l >> r;
        --l, --r;
        println("{}", Query(l, r, q));
    }
};

void Output() {
    return;
};
