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

typedef struct Coord {
    double x;
    double y;

    Coord operator- (const Coord& other) const {
        Coord delta = { other.x - x, other.y - y };
        return delta;
    }
}Coord;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Coord> dots(3), deltas(3);
    double length, maxLength = 0, minLength = 20001;
    double ans = -1;

    for (int i = 0; i < 3; i++) {
        cin >> dots[i].x >> dots[i].y;
    }

    for (int i = 0; i < 3; i++) {
        deltas[i] = dots[(i + 1) % 3] - dots[i];
        length = sqrt(pow(deltas[i].x, 2) + pow(deltas[i].y, 2));
        maxLength = max(maxLength, length);
        minLength = min(minLength, length);
    }

    if (deltas[2].y * deltas[0].x != deltas[0].y * deltas[2].x) {
        ans = 2.0 * (maxLength - minLength);
    }

    cout << setprecision(15) << fixed << ans << "\n";

    return 0;
}
