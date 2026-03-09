#include<bits/stdc++.h>
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
    constexpr Pii DT4[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
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

char res[2 * MAX];
int N, n, cnt;

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

    return true;
};

void Solve() {
    stack<int> stk;
    int st = 1;
    for (int i : Rng(0, N)) {
        cin >> n;
        if (stk.empty() || stk.top() < n) {
            for (; st <= n; st++) {
                stk.push(st);
                res[cnt++] = '+';
            }
        }
        if (stk.empty() || stk.top() > n) {
            cnt = 0;
            return;
        }
        stk.pop();
        res[cnt++] = '-';
    }
};

void Output() {
    if (!cnt) {
        println("NO");
        return;
    }
    for (char ch : res | views::take(cnt)) {
        println("{}", ch);
    }
    return;
};
