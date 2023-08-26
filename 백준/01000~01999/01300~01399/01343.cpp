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

string FillBoard(string& board);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string board, ans;

    cin >> board;

    ans = FillBoard(board);

    cout << ans;

    return 0;
};

string FillBoard(string& board) {
    string ans = board;
    size_t pos;

    vector<PSi> patterns = {
        {"AAAA",4},
        {"BB",2},
    };

    for (PSi& pattern : patterns) {
        while (true) {
            pos = ans.find(string(pattern.second, 'X'));
            if (pos == string::npos) {
                break;
            }
            ans.replace(pos, pattern.second, pattern.first);
        }
    }

    if (count(ans.begin(), ans.end(), 'X')) {
        ans = "-1";
    }
    
    return ans;
};