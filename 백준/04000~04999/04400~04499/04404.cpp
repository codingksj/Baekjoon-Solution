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
typedef vector<vector<int>> Matrix2Di;

typedef struct Coord {
    double x, y;
    double operator - (const Coord & other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
}Coord;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Coord G, D, hole;

    cin >> G.x >> G.y >> D.x >> D.y;

    while (cin >> hole.x >> hole.y){
        if ((hole - G) * 2 < (hole - D)) {
            cout << setprecision(3) << fixed 
                << "The gopher can escape through the hole at (" 
                << hole.x << "," << hole.y << ").";
            return 0;
        }
    }

    cout << "The gopher cannot escape.";
    return 0;
}