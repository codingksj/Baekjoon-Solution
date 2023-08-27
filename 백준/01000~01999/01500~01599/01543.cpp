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

int FindPatternAppearance(string& document, string& pattern);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string document, pattern;
    int ans;

    getline(cin, document);
    getline(cin, pattern);

    ans = FindPatternAppearance(document, pattern);

    cout << ans;

    return 0;
};

int FindPatternAppearance(string& document, string& pattern) {
    size_t pos;
    int dLength = document.length();
    int pLength = pattern.length();
    int nextPos = 0;
    int count = 0;

    while (nextPos < dLength) {
        pos = document.find(pattern, nextPos);
        if (pos == string::npos) {
            break;
        }
        count++;
        nextPos = pos + pLength;
    }

    return count;
};