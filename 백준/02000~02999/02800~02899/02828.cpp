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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, TC;
    int applePos;
    int totalMove = 0;
    int left, right;

    cin >> N >> M;
    cin >> TC;

    left = 1;
    right = left + M - 1;

    while (TC--) {
        cin >> applePos;

        if (applePos < left) {
            totalMove += left - applePos;
            left = applePos;
            right = left + M - 1;
        }

        else if (applePos > right) {
            totalMove += applePos - right;
            right = applePos;
            left = right - M + 1;
        }
    }

    cout << totalMove;

    return 0;
}
