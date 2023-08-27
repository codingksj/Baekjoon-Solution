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

int FindMinimumSet(string& N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string N;
    int ans;

    cin >> N;

    ans = FindMinimumSet(N);

    cout << ans;

    return 0;
};

int FindMinimumSet(string& N) {
    string curN = N;
    int digitCount[9] = { 0, };
    int ans;

    for (char digit : curN) {
        (digit == '6' || digit == '9') ? (digitCount[6]++) : (digitCount[digit - '0']++);
    }
    digitCount[6] = (digitCount[6] + 1) / 2;

    ans = *max_element(begin(digitCount), end(digitCount));

    return ans;
};