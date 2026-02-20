#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr double EPS = 1E-4;
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

V1<Ti3> V;
int N, mnDist = INF;

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

    V.resize(N);

    for (auto& [x, y, z] : V) {
        cin >> x >> y >> z;
    }

    return true;
};

void Solve() {
    ranges::sort(V);
    for (int i = 1; i < N; i++) {
        const auto& [x1, y1, z1] = V[i];
        int d1 = INF;
        int d2 = INF;
        for (int j = i - 1; j >= 0; j--) {
            const auto& [x2, y2, z2] = V[j];
            if (abs(x2 - x1) >= mnDist) {
                break;
            }
            int d = abs(x2 - x1) + abs(y2 - y1) + abs(z2 - z1);
            if (d < d1) {
                d2 = d1;
                d1 = d;
            }
            else if (d < d2) {
                d2 = d;
            }
        }
        for (int j = i + 1; j < N; j++) {
            const auto& [x2, y2, z2] = V[j];
            if (abs(x2 - x1) >= mnDist) {
                break;
            }
            int d = abs(x2 - x1) + abs(y2 - y1) + abs(z2 - z1);
            if (d < d1) {
                d2 = d1;
                d1 = d;
            }
            else if (d < d2) {
                d2 = d;
            }
        }
        if (d2 != INF) {
            mnDist = min(mnDist, d1 + d2);
        }
    }
};

void Output() {
    println("{}", mnDist);
    return;
};
