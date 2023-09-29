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

Pii FIndSeatCoord(const int R, const int C, const int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Pii coord, failed = { -1,-1 };
    int R, C, K;

    cin >> C >> R >> K;

    coord = FIndSeatCoord(R, C, K);

    (coord == failed) ?
        cout << 0:
        cout << coord.first << " " << coord.second;

    cout << "\n";

    return 0;
}

Pii FIndSeatCoord(const int R, const int C, const int K) {
    Matrix2D_i seats(R, vector<int>(C, 0));
    Pii coord = { -1,-1 };
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int dir = 1;
    int r = 0, c = 0;
    int i = 1;

    if (K <= R * C) {
        while (i < K) {
            seats[r][c] = i++;
            r += dr[dir];
            c += dc[dir];
            if (r < 0 || c < 0 || r >= R || c >= C || seats[r][c]) {
                r -= dr[dir];
                c -= dc[dir];
                dir = (dir + 3) % 4;
                r += dr[dir];
                c += dc[dir];
            }
        }
        coord = { c + 1, r + 1 };
    }

    return coord;
};
