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

typedef struct Coord {
    int x;
    int y;
}Coord;

Matrix2D_i FillMosaic(vector<pair<Coord, Coord>>& ranges, int N, int M);
int FindNotMosaickedArea(Matrix2D_i& mosaic, int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i mosaic;
    vector<pair<Coord, Coord>> ranges;
    pair<Coord, Coord> range;
    Coord start, end;
    int ans;
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> start.x >> start.y >> end.x >> end.y;
        range = { start, end };
        ranges.push_back(range);
    }

    mosaic = FillMosaic(ranges, N, M);
    ans = FindNotMosaickedArea(mosaic, M);

    cout << ans;

    return 0;
};

Matrix2D_i FillMosaic(vector<pair<Coord, Coord>>& ranges, int N, int M) {
    Matrix2D_i mosaic(101, vector<int>(101, 0));
    Coord start, end;
    int cnt = 0;

    for (pair<Coord, Coord>& p : ranges) {
        start = p.first;
        end = p.second;
        for (int x = start.x; x <= end.x; x++) {
            for (int y = start.y; y <= end.y; y++) {
                mosaic[x][y]++;
            }
        }
    }

    return mosaic;
};

int FindNotMosaickedArea(Matrix2D_i& mosaic, int M) {
    int count = 0;

    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            (mosaic[x][y] >  M) && count++;
        }
    }

    return count;
};