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

int CalculateScatteredness(char puzzle[4][4]);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    char puzzle[4][4];
    int ans;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> puzzle[i][j];
        }
    }
    ans = CalculateScatteredness(puzzle);

    cout << ans;

    return 0;
}

int CalculateScatteredness(char puzzle[4][4]) {
    int r, c;
    int distance;
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == '.') {
                continue;
            }
            r = (puzzle[i][j] - 'A') / 4;
            c = (puzzle[i][j] - 'A') % 4;
            distance = abs(r - i) + abs(c - j);
            ans += distance;
        }
    }
    return ans;
};