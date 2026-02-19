#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
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
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f; 
    constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50000;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<string> bads;
char converts[1 << 8];
string license;
int N, M;
bool isValid;

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
    converts['0'] = 'O';
    converts['1'] = 'L';
    converts['2'] = 'Z';
    converts['3'] = 'E';
    converts['5'] = 'S';
    converts['6'] = 'B';
    converts['7'] = 'T';
    converts['8'] = 'B';
    return;
};

bool Input() {
    cin >> N >> M;

    for (int i : Rng(0, N)) {
        cin >> license;
        bads.push_back(license);
    }

    return true;
};

void Solve() {
    isValid = true;
    ranges::sort(bads);

    auto CheckValid = [&](const string& license) {
        for (const auto& s : bads) {
            if (license.contains(s)) {
                return false;
            }
        }
        return true;
    };

    for (int i : Rng(0, M)) {
        cin >> license;
        for (char& ch : license) {
            unsigned char idx = ch;
            ch = max(ch, converts[idx]);
        }
        println("{}", CheckValid(license) ? "VALID" : "INVALID");
    }
};

void Output() {
    return;
};
