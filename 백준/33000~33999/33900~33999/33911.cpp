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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int counts[MAX + 1];
int N, a, b, c, cnt;

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

    for (int i : Rng(0, N)) {
        cin >> a >> b >> c;
        counts[a]++;
        counts[b]++;
        counts[c]++;
    }

    return true;
};

void Solve() {
    int rival = 0;
    int used = 0;
    for (int x : Rng(1, MAX + 1) | views::reverse) {
        if (counts[x] == 1) {
            rival++;
        }
        if (rival == 3) {
            return;
        }
        if (!counts[x]) {
            int n = MAX - ++used - rival;
            int r = 2 - rival;
            cnt += r > 1 ? n * (n - 1) / 2 : r ? n : 1;
        }
    }
};

void Output() {
    println("{}", cnt);
    return;
};
