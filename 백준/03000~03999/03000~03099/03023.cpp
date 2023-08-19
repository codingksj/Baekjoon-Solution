#include<iostream>
#include<sstream>
#include<bitset>
#include<set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

Words MakeFullCardBack(Words& pattern, Pii& rc, Pii& error);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words pattern, card;
    string line;
    Pii rc, error;

    cin >> rc.first >> rc.second;
    
    for (int i = 0; i < rc.first; i++) {
        cin >> line;
        pattern.push_back(line);
    }

    cin >> error.first >> error.second;

    card = MakeFullCardBack(pattern, rc, error);

    for (string& line : card) {
        cout << line << "\n";
    }

    return 0;
}

Words MakeFullCardBack(Words& pattern, Pii& rc, Pii& error) {
    Words fullCardBack;
    char c;
    int R = rc.first, C = rc.second;
    int errorR = error.first, errorC = error.second;

    fullCardBack.resize(2 * R);

    for (int r = 0; r < R; r++) {
        fullCardBack[r] = pattern[r] + pattern[r];

        for (int c = 0; c < C; c++) {
            fullCardBack[r][2 * C - (c + 1)] = fullCardBack[r][c];
        }

        fullCardBack[2 * R - (r + 1)] = fullCardBack[r];
    }

    c = fullCardBack[errorR - 1][errorC - 1];
    fullCardBack[errorR - 1][errorC - 1] = (c == '.') ? '#' : '.';
    
    return fullCardBack;
};