#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<random>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Register = array<int, 4>;
using FuncPtr = void (*)(Register&);
using Data = tuple<Register, ULL, ULL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n", DSLR = "DSLR";
    constexpr Pii DT4[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+4, MASK = 3, SHIFT = 2;
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

int table[MAX][4];
char op[MAX];
char res[MAX];
int par[MAX];
int visChk[MAX];
int TC, A, B, id, cnt;

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
    for (int n = 0; n < MAX; n++) {
        table[n][0] = (2 * n) % MAX;
        table[n][1] = n == 0 ? MAX - 1 : n - 1;
        table[n][2] = (n % 1000) * DIGITS + n / 1000;
        table[n][3] = (n / 10) + 1000 * (n % 10);
    }
    return;
};

bool Input() {
    cin >> A >> B;

    return true;
};

void Solve() {
    queue<int> q;
    q.push(A);
    visChk[A] = ++id;
    cnt = 0;

    while (!q.empty()) {
        int n = q.front(); q.pop();
        if (n == B) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nn = table[n][i];
            if (visChk[nn] != id) {
                q.push(nn);
                visChk[nn] = id;
                par[nn] = n;
                op[nn] = DSLR[i];
            }
        }
    }
    for (int n = B; n != A; n = par[n]) {
        res[cnt++] = op[n];
    }
    return;
};

void Output() {
    for (int i = cnt - 1; i >= 0; i--) {
        print("{}", res[i]);
    }
    println("");
    return;
};
