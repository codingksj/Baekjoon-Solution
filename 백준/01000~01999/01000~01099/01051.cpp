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

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

Words LoadSquare(const int R, const int C);
int FindMaxArea(const Words& square, const int R, const int C, const int maxSize);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words square;
    int R, C;
    int maxArea;

    cin >> R >> C;

    square = LoadSquare(R, C);
    maxArea = FindMaxArea(square, R, C, min(R, C));

    cout << maxArea << "\n";

    return 0;
}

Words LoadSquare(const int R, const int C) {
    Words square(R, string(C, '0'));

    for(string& line : square){
        cin >> line;
    }

    return square;
};

int FindMaxArea(const Words& square, const int R, const int C, const int maxSize) {
    int corner1, corner2, corner3, corner4;
    int nr, nc;
    int maxArea;

    if (maxSize == 1) {
        maxArea = maxSize * maxSize;

        return maxArea;
    }

    for (int r = 0; r <= R - maxSize; r++) {
        for (int c = 0; c <= C - maxSize; c++) {
            nr = r + maxSize - 1;
            nc = c + maxSize - 1;
            corner1 = square[r][c];
            corner2 = square[nr][c];
            corner3 = square[r][nc];
            corner4 = square[nr][nc];
            if ((corner1 == corner2) && (corner2 == corner3) && (corner3 == corner4)) {
                maxArea = maxSize * maxSize;

                return maxArea;
            }
        }
    }

    return FindMaxArea(square, R, C, maxSize - 1);
};