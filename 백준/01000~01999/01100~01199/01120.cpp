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

int FindMinDelta(const string& x, const string& y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string x, y;
    int ans;

    cin >> x >> y;

    ans = FindMinDelta(x, y);

    cout << ans << "\n";

    return 0;
}

int FindMinDelta(const string& x, const string& y) {
    int xLength = x.length();
    int yLength = y.length();
    int deltaLength = yLength - xLength;
    int delta = 0, minDelta = 51;

    for (int i = 0; i <= deltaLength; i++) {
        delta = 0;
        for (int j = 0; j < xLength; j++) {
            (x[j] != y[i + j]) && delta++;
        }
        minDelta = min(minDelta, delta);
    }

    return minDelta;
};