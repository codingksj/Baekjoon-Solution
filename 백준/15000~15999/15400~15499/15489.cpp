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

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

#define MAX 30

LL CalcPascalSum(const LL R, const LL C, const LL W);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL R, C, W;
    LL sum;

    cin >> R >> C >> W;

    sum = CalcPascalSum(R, C, W);

    cout << sum << "\n";

    return 0;
}

LL CalcPascalSum(const LL R, const LL C, const LL W) {
    Matrix2D_L dp(MAX + 1, vector<LL>(MAX + 1, 0));
    LL sum = 0;

    dp[1][1] = 1LL;

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (j == 1 || j == i) ? 1LL : dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j <= i; j++) {
            sum += dp[R + i][C + j];
        }
    }

    return sum;
};