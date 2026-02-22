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

LL N, K, Q, v1, v2;

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
    cin >> N >> K >> Q;

    return true;
};

void Solve() {
    auto CalcDist = [&](LL v1, LL v2) {
        int dist = 0;
        for (; v1 != v2; dist++) {
            if (v1 > v2) {
                v1 = (v1 - 1) / K;
            }
            else {
                v2 = (v2 - 1) / K;
            }
        }
        return dist;
    };
    while (Q--) {
        cin >> v1 >> v2;
        if (v1 > v2) {
            swap(v1, v2);
        }
        if (K == 1) {
            println("{}", v2 - v1);
        }
        else {
            println("{}", CalcDist(--v1, --v2));
        }
    }
};

void Output() {
    return;
};
