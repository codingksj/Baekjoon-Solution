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

LL Factorial(LL N);
bool CheckSumDecomposable(LL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bool isSumDecomposable;
    LL N;

    cin >> N;

    isSumDecomposable = CheckSumDecomposable(N);

    cout << (isSumDecomposable ? "YES" : "NO") << "\n";

    return 0;
}

LL Factorial(LL N) {
    if (N == 0 || N == 1) {
        return 1LL;
    }
    return N * Factorial(N - 1);
};

bool CheckSumDecomposable(LL N) {
    LL maximum = 0;
    LL sum = 0;
    LL curN = N;
    LL F = 0;
    LL dp[20] = { 0, };

    for (LL i = 0; i < 20; i++) {
        F = Factorial(i);
        maximum += F;
        dp[i] = F;
    }

    if (N > maximum || N == 0) {
        return false;
    }

    for (LL i = 19; i >= 0; i--) {
        if (dp[i] <= curN) {
            curN -= dp[i];
        }
    }

    return curN == 0;
};
