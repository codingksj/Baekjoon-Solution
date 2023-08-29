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

Words FillBoxWithCandies(int R);
int FindCandies(Words& box, int R, int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words box;
    int candyCount = 0;
    int TC;
    int R, C;

    cin >> TC;

    while (TC--) {
        cin >> R >> C;
        cin.ignore();

        box = FillBoxWithCandies(R);
        candyCount = FindCandies(box, R, C);

        cout << candyCount << "\n";
    }

    return 0;
}

Words FillBoxWithCandies(int R) {
    Words box(R);

    for (string& line : box) {
        cin >> line;
    }

    return box;
};

int FindCandies(Words& box, int R, int C) {
    int candyCount = 0;
    bool isCandy;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C - 2; c++) {
            isCandy = box[r].substr(c, 3) == ">o<";
            isCandy && candyCount++;
        }
    }

    for (int c = 0; c < C; c++) {
        for (int r = 0; r < R - 2; r++) {
            isCandy = 
                box[r][c] == 'v' &&
                box[r + 1][c] == 'o' &&
                box[r + 2][c] == '^';

            isCandy && candyCount++;
        }
    }

    return candyCount;
};