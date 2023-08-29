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

LL CountPossibleTriangles(LL match);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL match, ans;

    cin >> match;

    ans = CountPossibleTriangles(match);

    cout << ans;

    return 0;
}

LL CountPossibleTriangles(LL match) {
    LL s1, s2, s3;
    LL tCount = 0;

    for (s1 = 1; s1 < match; s1++) {
        for (s2 = s1; s2 < match; s2++) {
            s3 = match - (s1 + s2);
            if (s3 < s2) {
                break;
            }
            if (s1 + s2 > s3) {
                tCount++;
            }
        }
    }

    return tCount;
};