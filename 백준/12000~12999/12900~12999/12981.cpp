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
using Arr = array<int, 1 << 19>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 5E+5, LIMIT = 1E+4;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int balls[3];
int box;

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
    for (int i : Rng(0, 3)) {
        cin >> balls[i];
    }

    return true;
};

void Solve() {
    for (int i : Rng(0, 3)) {
        box += balls[i] / 3;
        balls[i] %= 3;
    }
    bool isOnly = false;
    int target = -1;
    for (int i : Rng(0, 3)) {
        if (!balls[(i + 1) % 3] && !balls[(i + 2) % 3]) {
            target = i;
            isOnly = true;
            break;
        }
    }
    box += isOnly ? balls[target] > 0 : ranges::max(balls);
    return;
};

void Output() {
    println("{}", box);
    return;
};
