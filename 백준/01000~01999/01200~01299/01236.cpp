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
typedef pair<LL, LL> PLL;
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;

int FindMinGuard(vector<string>& words, int R, int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> lines;
    string line;
    int R, C;
    int answer;

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        cin >> line;
        lines.push_back(line);
    }

    answer = FindMinGuard(lines, R, C);

    cout << answer;

    return 0;
}

int FindMinGuard(vector<string>& words, int R, int C) {
    bitset<51> checkRow, checkCol;
    bool isGuarded;
    int minGuard;
    char status;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            status = words[r][c];
            isGuarded = (status == 'X');
            !checkRow[r] && isGuarded && (checkRow[r] = 1);
            !checkCol[c] && isGuarded && (checkCol[c] = 1);
        }
    }
    minGuard = max(R - checkRow.count(), C - checkCol.count());
    return minGuard;
};