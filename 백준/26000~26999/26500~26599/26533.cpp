#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>
#include<random>

using namespace std;

using Ui = unsigned int;
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+2;
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

bool visChk[MAX][MAX];
string mp[MAX];
int N;

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
        cin >> mp[i];
    }

    return true;
};

void Solve() {
    queue<Pii> q;

    q.push({ 0, 0 });
    visChk[0][0] = true;
    
    auto Ok = [&](int r, int c) {return (Ui)r < N && (Ui)c < N; };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i : {1, 2}) {
            const auto& [dr, dc] = DT4[i];
            int nr = r + dr;
            int nc = c + dc;
            if (Ok(nr, nc) && !visChk[nr][nc] && mp[nr][nc] == '.') {
                q.push({ nr, nc });
                visChk[nr][nc] = true;
            }
        }
    }
};

void Output() {
    println("{}", visChk[N - 1][N - 1] ? "Yes" : "No");
    return;
};
