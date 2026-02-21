#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
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

struct Trie {
    Trie* childs[2];

    Trie() {
        childs[0] = childs[1] = nullptr;
    }
    void Insert(int n) {
        Trie* cur = this;
        for (int i = 31; i >= 0; i--) {
            int b = (n >> i) & 1;
            if (cur->childs[b] == nullptr) {
                cur->childs[b] = new Trie;
            }
            cur = cur->childs[b];
        }
    }
    int Find(int n) {
        Trie* cur = this;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int b = (~n >> i) & 1;
            if (cur->childs[b] == nullptr) {
                b = !b;
            }
            res |= b << i;
            cur = cur->childs[b];
        }
        return n ^ res;
    };
};
Trie* root = new Trie;
int A[MAX + 1];
int N, n, mxN;

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

    for (int i : Rng(0, N)) {
        cin >> A[i];
        root->Insert(A[i]);
    }

    return true;
};

void Solve() {
    for (int i : Rng(0, N)) {
        mxN = max(mxN, root->Find(A[i]));
    }
};

void Output() {
    println("{}", mxN);
    return;
};
