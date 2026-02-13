#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
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
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MIN = 10'000, MAX = 20'001, MAX_DOT = 3'000;
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

bitset<MAX * MAX> isExist;
Pii dots[MAX_DOT + 1];
int TC, N, x, y, mxArea;

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

    return true;
};

void Solve() {
    mxArea = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        x += MIN;
        y += MIN;
        dots[i] = { x,y };
        isExist[x * MAX + y] = true;
    }
    auto Ok = [&](int x, int y) {
        return !(x < 0 || x > MAX || y < 0 || y > MAX) && isExist[x * MAX + y];
    };
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            const auto& [x1, y1] = dots[i];
            const auto& [x2, y2] = dots[j];
            int dx = x2 - x1, dy = y2 - y1;
            int area = dx * dx + dy * dy;
            if (area <= mxArea) {
                continue;
            }
            int x3 = x1 - dy, y3 = y1 + dx;
            int x4 = x2 - dy, y4 = y2 + dx;
            if (Ok(x3, y3) && Ok(x4, y4)) {
                mxArea = area;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        const auto& [x, y] = dots[i];
        isExist[x * MAX + y] = false;
    }
    return;
};

void Output() {
    println("{}", mxArea);
    return;
};
