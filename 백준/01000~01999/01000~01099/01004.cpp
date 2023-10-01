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

typedef struct Coord {
    int x;
    int y;

    int operator- (const Coord& other) const {
        int dx = other.x - x;
        int dy = other.y - y;
        int distance = dx * dx + dy * dy;

        return distance;
    }
}Coord;

int CountInOut(const Coord& src, const Coord& dest, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Coord src, dest;
    int TC, N;
    int inOutCount;

    cin >> TC;

    while (TC--) {
        cin >> src.x >> src.y >> dest.x >> dest.y;
        cin >> N;

        inOutCount = CountInOut(src, dest, N);

        cout << inOutCount << "\n";
    }

    return 0;
}

int CountInOut(const Coord& src, const Coord& dest, const int N) {
    Coord system;
    int r, in, out;
    int inOutCount;

    in = out = 0;

    for (int i = 0; i < N; i++) {
        cin >> system.x >> system.y >> r;

        (system - src < (r * r)) && (system - dest > (r * r)) && out++;
        (system - src > (r * r)) && (system - dest < (r * r)) && in++;
    }

    inOutCount = in + out;

    return inOutCount;
};