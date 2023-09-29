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

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

vector<int> LoadVector(const int N);
int CalcMaximumSubArraySum(const vector<int>& V, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> V;
    int TC, N, ans;

    cin >> TC;

    while (TC--) {
        cin >> N;

        V = LoadVector(N);
        ans = CalcMaximumSubArraySum(V, N);

        cout << ans << "\n";
    }

    return 0;
}

vector<int> LoadVector(const int N) {
    vector<int> V(N);

    for (int& e : V) {
        cin >> e;
    }

    return V;
};

int CalcMaximumSubArraySum(const vector<int>& V, const int N) {
    vector<int> dp(N);
    int ans = dp[0] = V[0];

    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1] + V[i], V[i]);
        ans = max(ans, dp[i]);
    }

    return ans;
};