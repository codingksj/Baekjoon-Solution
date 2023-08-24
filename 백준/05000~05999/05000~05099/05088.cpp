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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
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

#define PI 3.141592653589793

void InitGrid(int grid[102][102], int X, int Y, int size);
void HideTreasures(int grid[102][102], int N);
int FindTreasures(int grid[102][102], int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int grid[102][102];
    int X, Y;
    int M, N, treasure;

    while (cin >> X >> Y) {
        if (X == 0 && Y == 0) {
            break;
        }

        cin >> M;

        InitGrid(grid, X, Y, 101);
        HideTreasures(grid, M);

        cin >> N;
        treasure = FindTreasures(grid, N);

        cout << treasure << "\n";
    }

    return 0;
}

void InitGrid(int grid[102][102], int X, int Y, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
};

void HideTreasures(int grid[102][102], int N) {
    int x, y;

    while (N--) {
        cin >> x >> y;
        grid[x][y]++;
    }
};

int FindTreasures(int grid[102][102], int N) {
    int x, y;
    int treasure = 0;

    while (N--) {
        cin >> x >> y;
        treasure += grid[x][y];
    }

    return treasure;
};