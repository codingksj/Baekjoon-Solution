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
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

ULL CalcSum(ULL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    ULL N;
    ULL answer;
    
    cin >> N;

    answer = CalcSum(N);
    
    cout << answer;

    return 0;
}

ULL CalcSum(ULL N) {
    ULL sum;
    
    sum = (N - 1) * N * (N + 1) / 2;
    
    return sum;
};