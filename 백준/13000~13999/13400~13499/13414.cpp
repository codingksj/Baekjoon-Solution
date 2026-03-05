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
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+8, MAX_L = 5E+5;
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

bitset<MAX + 1> visChk;
stack<int> stk;
int ids[MAX_L];
int K, L;

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
    cin >> K >> L;

    return true;
};

void Solve() {
    for (int i = 0; i < L; i++) {
        cin >> ids[i];
    }
    for (int i = L - 1; i >= 0; i--) {
        int id = ids[i];
        if (!visChk[id]) {
            visChk[id] = true;
            stk.emplace(id);
        }
    }
};

void Output() {
    for (int i = 0; !stk.empty() && i < K; i++) {
        println("{:08}", stk.top());
        stk.pop();
    }
    return;
};
