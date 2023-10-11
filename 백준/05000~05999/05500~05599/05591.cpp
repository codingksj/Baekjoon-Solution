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
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

int FindMaxSubSum(const vector<int>& pxSum, const int N, const int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> V;
    vector<int> prefixSum;
    int N, K;
    int sum = 0;
    int maxSubSum;

    cin >> N >> K;

    V.resize(N);
    prefixSum.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> V[i];
        sum += V[i];
        prefixSum[i] = sum;
    }

    maxSubSum = FindMaxSubSum(prefixSum, N, K);

    cout << maxSubSum << "\n";

    return 0;
}

int FindMaxSubSum(const vector<int>& pxSum, const int N, const int K) {
    int maxSubSum = pxSum[K - 1];

    for (int i = K; i < N; i++) {
        maxSubSum = max(maxSubSum, pxSum[i] - pxSum[i - K]);
    }

    return maxSubSum;
};