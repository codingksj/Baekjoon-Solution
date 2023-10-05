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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

Words LoadInput(const int N);
Words MakeProgress(const Words& mineMap, const Words& clicks, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words mineMap, clicks, progress;
    int N;

    cin >> N;

    mineMap = LoadInput(N);
    clicks = LoadInput(N);
    progress = MakeProgress(mineMap, clicks, N);

    for (const string& line : progress) {
        cout << line << "\n";
    }

    return 0;
}

Words LoadInput(const int N) {
    Words board(N);

    for (string& line : board) {
        cin >> line;
    }

    return board;
};

Words MakeProgress(const Words& mineMap, const Words& clicks, const int N) {
    Words result = clicks;
    int dr[] = { -1,-1,0,1,1,1,0,-1 };
    int dc[] = { 0,1,1,1,0,-1,-1,-1 };
    int nr, nc;
    int bombCount;
    bool isExplode = false;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (clicks[r][c] != 'x') {
                continue;
            }
            if (mineMap[r][c] == '*') {
                isExplode = true;
                continue;
            }
            bombCount = 0;

            for (int i = 0; i < 8; i++) {
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    continue;
                }
                (mineMap[nr][nc] == '*') && bombCount++;
            }
            result[r][c] = (char)('0' + bombCount);
        }
    }

    if (isExplode) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (mineMap[r][c] == '*') {
                    result[r][c] = '*';
                }
            }
        }
    }

    return result;
};