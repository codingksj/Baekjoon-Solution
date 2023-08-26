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

int FindKSejunNum(int N, int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    int cnt;

    cin >> N >> K;

    cnt = FindKSejunNum(N, K);

    cout << cnt;

    return 0;
};

int FindKSejunNum(int N, int K) {
    vector<int> maxFactors(N + 1, 0);
    int cnt = min(N, K);

    for (int i = 2; i <= N; i++) {
        if (maxFactors[i]) {
            continue;
        }
        for (int j = i; j <= N; j += i) {
            maxFactors[j] = max(maxFactors[j], i);
        }
    }

    for (int i = cnt + 1; i <= N; i++) {
        (maxFactors[i] <= K) && (cnt++);
    }

    return cnt;
};