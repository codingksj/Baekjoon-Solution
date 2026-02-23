#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>
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
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50;
    constexpr auto Rng = views::iota;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

string words[MAX];
string alphas;
string res;
int TC, tc, N;

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
    for (char ch : Rng('A', 'Z' + 1)) {
        alphas += ch;
    }
    return;
};

bool Input() {
    cin >> N;

    for (int i : Rng(0, N)) {
        cin >> words[i];
    }

    return true;
};

void Solve() {
    random_device rd;
    mt19937 gen(rd());

    for (int i : Rng(0, N)) {
        if (words[i].size() == 1) {
            res = "IMPOSSIBLE";
            return;
        }
    }
    for (int test : Rng(0, 10000)) {
        ranges::shuffle(alphas, gen);
        bool isOk = true;
        for (int i : Rng(0, N)) {
            if (alphas.contains(words[i])) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            res = alphas;
            return;
        }
    }
    res = "IMPOSSIBLE";
};

void Output() {
    println("Case #{}: {}", ++tc, res);
    return;
};
