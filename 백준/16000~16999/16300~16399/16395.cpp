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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;

#define MAX 32

LL dp[MAX][MAX];
LL nCk(int n, int k);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	
	cin >> n >> k;
	cout << nCk(n - 1, k - 1);
    
    return 0;
}

LL nCk(int n, int k) {
    for (int i = 0; i < MAX; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i < MAX; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}