#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<random>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 5E+5;
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

map<int, int> mp;
int A[MAX + 1];
int TC, N, a, n1, n2, idx1 = -1, idx2 = -1;

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

    for (int i : Rng(1, N + 1)) {
        cin >> a;
        A[i] = a;
        if (mp.count(a)) {
            idx1 = i;
            idx2 = mp[a];
            return true;
        }
        mp[a] = i;
    }
    return true;
};

void Solve() {
    if (idx1 != -1) {
        return;
    }
    if (mp.count(1)) {
        idx1 = mp[1];
        idx2 = mp.rbegin()->second;
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, N);

    while (true) { 
        idx1 = dis(gen);
        idx2 = dis(gen);
        if (idx1 == idx2) {
            continue;
        } 
        if (!(A[idx2] % A[idx1])) {
            return;
        }
        if (!(A[idx1] % A[idx2])) {
            swap(idx1, idx2); 
            return;
        }
    }
};

void Output() {
    println("{} {}", idx1, idx2);
    return;
};
