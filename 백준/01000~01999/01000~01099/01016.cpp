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

LL CountNotDividedBySquare(LL m, LL M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    LL m, M;
    LL ans;

    cin >> m >> M;

    ans = CountNotDividedBySquare(m, M);

    cout << ans;

    return 0;
}


LL CountNotDividedBySquare(LL m, LL M) {
    vector<bool> checks;
    LL square, start, index;
    int size = M - m + 1;
    int ans;
    
    checks.resize(size, true);

    for (LL N = 2; N * N <= M; N++) {
        square = N * N;
        start = ceil(m / (double)square);

        for (LL i = start; i * square <= M; i++) {
            index = i * square - m;
            if (checks[index]) {
                checks[index] = false;
            }
        }
    }

    ans = count(checks.begin(), checks.end(), true);

    return ans;
};
