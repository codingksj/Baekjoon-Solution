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

LL Combination(const LL N, const LL R);
double CalcLottoProbablity(const int N, const int M, const int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, K;
    double probablity;

    cin >> N >> M >> K;

    probablity = CalcLottoProbablity(N, M, K);

    cout << setprecision(15) << fixed << probablity << "\n";

    return 0;
}

LL Combination(const LL N, const LL R) {
    int dp[10][10];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= R; j++) {
            dp[i][j] = ((i == j) || (j == 0)) ? 1 : dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[N][R];
};
double CalcLottoProbablity(const int N, const int M, const int K) {
    double head, tail;
    double percent = 0;

    for (int k = K; k <= M; k++) {
        if (N - M < M - k) {
            continue;
        }
        head = Combination(M, k) * Combination(N - M, M - k);
        tail = Combination(N, M);
        percent += head / tail;
    }

    return percent;
};