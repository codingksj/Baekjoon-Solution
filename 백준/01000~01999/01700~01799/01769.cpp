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

Pib CountConvert(string& X, int count);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string X;
    Pib ans;

    cin >> X;
    
    ans = CountConvert(X, 0);

    cout << ans.first << "\n"
        << (ans.second ? "YES" : "NO") << "\n";

    return 0;
};

Pib CountConvert(string& X, int count) {
    Pib ans;
    string copy = X;
    int length = copy.length();
    int sum = 0;

    if (length == 1) {
        ans.first = count;
        ans.second = copy[0] == '3' || copy[0] == '6' || copy[0] == '9';

        return ans;
    }
    
    for (char digit : copy) {
        sum += (digit - '0');
    }

    copy = to_string(sum);

    return CountConvert(copy, count + 1);
};