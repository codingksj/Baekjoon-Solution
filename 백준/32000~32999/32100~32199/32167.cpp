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
using Ti4 = tuple<int, int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 100'000;
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

bitset<MAX> pos[ALPHABETS];
string s, q;
int Q;

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
    cin >> s >> Q;

    return true;
};

void Solve() {
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        pos[s[i] - 'a'][i] = true;
    }
    while (Q--) {
        cin >> q;
        int l = q[0] - 'a';
        int r = q.back() - 'a';
        int len = stoi(q.substr(1, q.size() - 2));
        println("{}", ((pos[l] << (len + 1)) & pos[r]).count());
    }
};

void Output() {
    return;
};
