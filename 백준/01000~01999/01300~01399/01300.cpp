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

LL CountLessThanX(LL X, LL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    LL N, K;
    LL start, mid, end;
    LL count;

    cin >> N >> K;

    start = 1;
    end = N * N;

    while (start <= end) {
        mid = (start + end) / 2;
        count = CountLessThanX(mid, N);
        count < K ? start = mid + 1 : end = mid - 1;
    }

    cout << start;

    return 0;
}

LL CountLessThanX(LL X, LL N) {
    LL sum = 0;

    for (LL i = 1; i <= N; i++) {
        sum += min(X / i, N);
    }

    return sum;
};