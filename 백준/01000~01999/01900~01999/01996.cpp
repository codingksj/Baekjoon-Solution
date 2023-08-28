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

Words GetMineInfo(int N);
Words MakeMineMap(Words& mineInfo, int N);
void UpdateNearCells(Words& mineInfo, Words& mineMap, int r, int c);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words mineInfo, mineMap;
    int N;

    cin >> N;

    mineInfo = GetMineInfo(N);
    mineMap = MakeMineMap(mineInfo, N);

    for (string& line : mineMap) {
        cout << line << "\n";
    }
    return 0;
};

Words GetMineInfo(int N) {
    Words mineInfo(N);

    for (string& line : mineInfo) {
        cin >> line;
    }

    return mineInfo;
};

Words MakeMineMap(Words& mineInfo, int N) {
    Words mineMap(N, string(N, '0'));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (isdigit(mineInfo[r][c])) {
                UpdateNearCells(mineInfo, mineMap, r, c);
            }
        }
    }

    return mineMap;
};

void UpdateNearCells(Words& mineInfo, Words& mineMap, int r, int c) {
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int nx, ny, cur;
    int delta = mineInfo[r][c] - '0';
    int N = mineInfo.size();

    mineMap[r][c] = '*';

    for (int i = 0; i < 8; i++) {
        nx = r + dx[i];
        ny = c + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            continue;
        }
        if (mineMap[nx][ny] == 'M' || mineInfo[nx][ny] != '.') {
            continue;
        }
        cur = mineMap[nx][ny];
        mineMap[nx][ny] = (cur + delta <= '9' ? cur + delta : 'M');
    }
}