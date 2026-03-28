#include <bits/stdc++.h>
#include <ranges>
#include <print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
using Team = tuple<int, int, string>;

template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
    constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<Team> teams;
string info[MAX];
int scores[MAX];
int P, p, N;

int main() {
    FastIO();
    SetUp();

    while (Input()) {
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
    cin >> P;
    if (!P) {
        return false;
    }
    for (int i : Rng(0, P)) {
        cin >> scores[i];
    }
    cin >> N;
    cin.ignore();
    for (int i : Rng(0, N)) {
        getline(cin, info[i]);
    }
    return true;
};

void Solve() {
    auto ToLower = [](string s) {
        for (char& ch : s) {
            ch = tolower(ch);
        }
        return s;
    };
    auto Cmp = [&](const Team& t1, const Team& t2) {
        const auto& [_1, score1, name1] = t1;
        const auto& [_2, score2, name2] = t2;
        return score1 != score2 ? score1 > score2 : ToLower(name1) < ToLower(name2);
    };
    auto Extract = [](const string& s) {
        Team team;
        auto& [_, score, name] = team;
        auto res = ranges::to<V1<string>>(s | Split(','));
        name = res[0];
        for (int i = 1; i <= P; i++) {
            if (res[i].back() != '-') {
                score += scores[i - 1];
            }
        }
        return team;
    };
    teams.resize(N);
    for (int i : Rng(0, N)) {
        teams[i] = Extract(info[i]);
    }
    ranges::sort(teams, Cmp);
    for (int i : Rng(0, N)) {
        auto& [ord, score, _] = teams[i];
        ord = (i > 0 && score == get<1>(teams[i - 1])) ? get<0>(teams[i - 1]) : i + 1;
    }
};

void Output() {
    println("Contest {}", ++p);
    for (const auto& [order, score, name] : teams) {
        println("{} {} {}", order, name, score);
    }
};
