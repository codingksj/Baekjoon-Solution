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

LL CountPossibleCombination(const vector<LL>& A, const LL N, const LL M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> A;
    LL N, M;
    LL count;

    cin >> N >> M;

    A.resize(N);

    for (LL& a : A) {
        cin >> a;
    }

    count = CountPossibleCombination(A, N, M);

    cout << count << "\n";

    return 0;
}

LL CountPossibleCombination(const vector<LL>& A, const LL N, const LL M) {
    LL start = 0, end = 0;
    LL sum = 0, count = 0;

    while (true) {
        if (sum >= M) {
            sum -= A[start++];
        }
        else if (end == N) {
            break;
        }
        else {
            sum += A[end++];
        }
        (sum == M) && count++;
    }

    return count;
};