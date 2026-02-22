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
    constexpr PLL NONE = { -1,-1 };
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 500, PICK = 20;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void MakeDFS(int depth, LL sum, int pick);
void FindDFS(int depth, LL sum, int pick);
void Output();

unordered_map<LL, int> sums;
LL A[MAX + 1];
int idx[MAX + 1];
int pick1[PICK];
int pick2[PICK];
LL target;
int res, TC, tc, N, cnt;

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while (TC--) {
        Input();
        Solve();
        Output();
    }

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
        cin >> A[i];
    }

    return true;
};

void Solve() {
    random_device rd;
    mt19937 gen(rd());
    res = -1;
    target = -1;

    for (int i = 0; i < 8; i++) {
        iota(idx, idx + N, 0);
        shuffle(idx, idx + N, gen);
        sums.clear();
        cnt = 0;
        for (int i = 0; i < PICK; i++) {
            pick1[i] = idx[2 * i];
            pick2[i] = idx[2 * i + 1];
        }
        MakeDFS(0, 0, 0);
        sums.erase(0);
        FindDFS(0, 0, 0);
        if (res != -1) {
            break;
        }
    }
};

void MakeDFS(int depth, LL sum, int pick) {
    if (depth == PICK) {
        sums[sum] = pick;
        return;
    }
    MakeDFS(depth + 1, sum, pick);
    MakeDFS(depth + 1, sum + A[pick1[depth]], (pick | 1 << depth));
};

void FindDFS(int depth, LL sum, int pick) {
    if (res != -1) {
        return;
    }
    if (sums.count(sum)) {
        res = pick;
        target = sum;
        return;
    }
    if (depth == PICK) {
        return;
    }
    FindDFS(depth + 1, sum, pick);
    FindDFS(depth + 1, sum + A[pick2[depth]], (pick | 1 << depth));
};

void Output() {
    println("Case #{}:", ++tc);
    if (res == -1) {
        println("Impossible");
        return;
    }
    int res1 = sums[target];
    int res2 = res;
    int b1 = bit_width((size_t)res1) - 1;
    int b2 = bit_width((size_t)res2) - 1;
    for (int i = 0; i < 20; i++) {
        if ((1 << i) & res1) {
            print("{}{}", A[pick1[i]], SEPS[i == b1]);
        }
    }
    for (int i = 0; i < 20; i++) {
        if ((1 << i) & res2) {
            print("{}{}", A[pick2[i]], SEPS[i == b2]);
        }
    }
    return;
};
