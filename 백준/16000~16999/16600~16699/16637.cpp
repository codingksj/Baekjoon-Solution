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
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 10;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int opIdx, int val);
int Calc(int n1, int n2, char op);
void Output();

string s;
char opers[MAX + 1];
int A[MAX + 1];
int N, mxVal = INT_MIN, mxDepth;

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
    cin >> N >> s;

    for (int i : Rng(0, N) | Step(2)) {
        A[i / 2] = s[i] - '0';
    }
    for (int i : Rng(1, N) | Step(2)) {
        opers[i / 2] = s[i];
    }
    return true;
};

void Solve() {
    mxDepth = N / 2;
    DFS(0, A[0]);
    return;
};

void DFS(int opIdx, int val) {
    if (opIdx >= mxDepth) {
        mxVal = max(mxVal, val);
        return;
    }
    int nxt = Calc(val, A[opIdx + 1], opers[opIdx]);
    DFS(opIdx + 1, nxt);
    if (opIdx + 1 < mxDepth) {
        int inVal = Calc(A[opIdx + 1], A[opIdx + 2], opers[opIdx + 1]);
        int nxt = Calc(val, inVal, opers[opIdx]);
        DFS(opIdx + 2, nxt);
    }
};

int Calc(int n1, int n2, char op) {
    return op == '*' ? n1 * n2 : op == '+' ? n1 + n2 : n1 - n2;
};

void Output() {
    println("{}", mxVal);
    return;
};
