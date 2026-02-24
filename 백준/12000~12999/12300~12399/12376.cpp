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
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 10;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

struct Student {
    int r, idx;
    double x, y;
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

Student S[MAX];
int TC, N, W, L, tc;

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
    cin >> N >> W >> L;

    for (int i : Rng(0, N)) {
        cin >> S[i].r;
        S[i].idx = i;
    }
    return N;
};

void Solve() {
    auto Cmp = [&](const Student& s1, const Student& s2) {
        return s1.r > s2.r;
    };
    auto Cmp2 = [&](const Student& s1, const Student& s2) {
        return s1.idx < s2.idx;
    };
    ranges::sort(S, S + N, Cmp);
    S[0].x = 0, S[0].y = 0;
    S[1].x = W, S[1].y = L;
    if (N < 3) {
        return;
    }
    auto GetDist = [&](int i, int j) {
        double dx = S[i].x - S[j].x;
        double dy = S[i].y - S[j].y;
        return dx * dx + dy * dy;
    };
    auto HasCollide = [&](int me) {
        for (int i = 0; i < me ; i++) {
            double rSum = S[i].r + S[me].r;
            if (GetDist(i, me) < rSum * rSum) {
                return true;
            }
        }
        return false;
    };
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> xDis(0, W);
    uniform_real_distribution<double> yDis(0, L);

    auto PlaceDot = [&](int i) {
        for (int retry = 0; retry < 100; retry++) {
            S[i].x = xDis(gen);
            S[i].y = yDis(gen);
            if (!HasCollide(i)) {
                return true;
            }
        }
        return false;
    };
    for (int t : Rng(0, 1000)) {
        bool isOk = true;
        for (int i = 2; i < N; i++) {
            if (!PlaceDot(i)) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            ranges::sort(S, S + N, Cmp2);
            return;
        }
    }
    return;
};

void Output() {
    print("Case #{}: ", ++tc);
    for (int i : Rng(0, N)) {
        print("{:.1f} {:.1f}{}", S[i].x, S[i].y, SEPS[i == N - 1]);
    }
    return;
};
