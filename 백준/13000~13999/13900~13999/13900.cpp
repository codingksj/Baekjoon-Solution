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

vector<LL> LoadPrefixSum(const int N);
LL CalcSumOfPairs(const vector<LL>& prefixSum, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> prefixSum;
    LL sum;
    int N;

    cin >> N;

    prefixSum = LoadPrefixSum(N);
    sum = CalcSumOfPairs(prefixSum, N);

    cout << sum << "\n";

    return 0;
}

vector<LL> LoadPrefixSum(const int N) {
    vector<LL> prefixSum(N);
    LL sum = 0;

    for (LL& e : prefixSum) {
        cin >> e;
        sum += e;
        e = sum;
    }

    return prefixSum;
};

LL CalcSumOfPairs(const vector<LL>& prefixSum, const int N) {
    LL sum = 0;

    for (int i = 0; i < N; i++) {
        sum += (prefixSum[N - 1] - prefixSum[i]) 
            * (i ? prefixSum[i] - prefixSum[i - 1] : prefixSum[i]);
    }

    return sum;
};