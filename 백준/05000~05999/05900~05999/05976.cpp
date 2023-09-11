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

void FillSpiral(Matrix2D_i& spiral, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i spiral;
    int N;

    cin >> N;

    FillSpiral(spiral, N);

    for (vector<int>& R : spiral) {
        for (int& C : R) {
            cout << C << " ";
        }
        cout << "\n";
    }

    return 0;
}

void FillSpiral(Matrix2D_i& spiral, int N) {
    spiral.resize(N, vector<int>(N, 0));

    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int dir = 0;
    int r = 0, c = 0;
    int i = 1;

    while (i <= N * N) {
        spiral[r][c] = i++;
        r += dr[dir];
        c += dc[dir];
        if (r < 0 || c < 0 || r >= N || c >= N || spiral[r][c]) {
            r -= dr[dir];
            c -= dc[dir];
            dir = (dir + 1) % 4;
            r += dr[dir];
            c += dc[dir];
        }
    }
};