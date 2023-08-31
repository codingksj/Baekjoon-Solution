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
#include<tuple>
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

typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;

Words GetMineInfo(int R, int C);
Words MakeMineMap(Words& mineInfo, int R, int C);
char UpdatePos(Words& mineInfo, char& cur, int r, int c);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words mineInfo, mineMap;
    int R, C;

    while (cin >> R >> C) {
        if (R == 0 && C == 0) {
            break;
        }
        mineInfo = GetMineInfo(R, C);
        mineMap = MakeMineMap(mineInfo, R, C);

        for (string& line : mineMap) {
            cout << line << "\n";
        }
    }

    return 0;
}

Words GetMineInfo(int R, int C) {
    Words mineInfo(R, string(C, '.'));

    for (string& line : mineInfo) {
        cin >> line;
    }

    return mineInfo;
};

Words MakeMineMap(Words& mineInfo, int R, int C) {
    Words mineMap = mineInfo;
    char cur;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (mineMap[r][c] != '*') {
                mineMap[r][c] = '0';
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cur = mineMap[r][c];
            if (cur == '*') {
                continue;
            }
            mineMap[r][c] = UpdatePos(mineInfo, cur, r, c);
        }
    }

    return mineMap;
};

char UpdatePos(Words& mineInfo, char& cur, int r, int c) {
    char newCur;
    int R = mineInfo.size();
    int C = mineInfo[0].size();
    int dr[] = { -1,-1,0,1,1,1,0,-1 };
    int dc[] = { 0,1,1,1,0,-1,-1,-1 };
    int mineCount = 0;
    int nr, nc;

    for (int i = 0; i < 8; i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
            continue;
        }
        (mineInfo[nr][nc] == '*') && mineCount++;
    }

    newCur = cur + mineCount;

    return newCur;
};