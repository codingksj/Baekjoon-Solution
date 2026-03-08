#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<random>

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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 100, TRY = 10'000, CAND = 10;
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

bool A[MAX][MAX];
int idx[CAND][MAX];
int happy[MAX];
int N, good = -1;

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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    return true;
};

void Solve() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, N - 1);
    auto CalcHappy = [&](int* target) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int me = target[i];
            int left = i == 0 ? target[N - 1] : target[i - 1];
            if (A[me][left]) {
                cnt++;
            }
        }
        return cnt;
    };
    auto Mutate = [&](int* target, int cand) {
        for (int i = 0; i < N - 1; i++) {
            int l1 = i == 0 ? target[N - 1] : target[i - 1];
            int r1 = target[i + 1];
            int me1 = target[i];
            for (int j = i + 1; j < N; j++) {
                int l2 = target[j - 1];
                int r2 = j == N - 1 ? target[0] : target[j + 1];
                int me2 = target[j];
                int prv, cur;
                if (j - i == 1 || j - i == N - 1) {
                    prv = A[l1][me1] + A[r2][me2];
                    cur = A[l1][me2] + A[r2][me1];
                }
                else {
                    prv = A[l1][me1] + A[r1][me1] + A[l2][me2] + A[r2][me2];
                    cur = A[l1][me2] + A[r1][me2] + A[l2][me1] + A[r2][me1];
                }
                if (prv < cur) {
                    swap(target[i], target[j]);
                    happy[cand] += cur - prv;
                    return;
                }
            }
        }
        return;
    };
    for (int cand = 0; cand < CAND; cand++) {
        auto target = idx[cand];
        iota(target, target + N, 0);
        shuffle(target, target + N, gen);
        happy[cand] = CalcHappy(idx[cand]);
        if (happy[cand] == N) {
            good = cand;
            return;
        }
    }
    for (int step = 0; step < TRY; step++) {
        for (int cand = 0; cand < CAND; cand++) {
            int prvHappy = happy[cand];
            if (gen() & 1) {
                Mutate(idx[cand], cand);
            }
            else {
                int i = dis(gen);
                int j = dis(gen);
                if (i == j) {
                    Mutate(idx[cand], cand);
                }
                else {
                    if (i > j) {
                        swap(i, j);
                    }
                    reverse(idx[cand] + i, idx[cand] + j + 1);
                    int curHappy = CalcHappy(idx[cand]);
                    if (curHappy >= prvHappy) {
                        happy[cand] = curHappy;
                    }
                    else {
                        reverse(idx[cand] + i, idx[cand] + j + 1);
                    }
                }
            }
            if (happy[cand] == N) {
                good = cand;
                return;
            }
        }
    }
};

void Output() {
    if (good == -1) {
        println("-1");
    }
    else {
        for (int i : Rng(0, N)) {
            print("{}{}", idx[good][i] + 1, SEPS[i == N - 1]);
        }
    }
    return;
};
