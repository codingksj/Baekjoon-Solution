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
typedef vector<vector<LL>> Matrix2D_L;

Pii GetNthFraction(int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Pii ans;
    int N;

    while (cin >> N) {
        ans = GetNthFraction(N);

        cout << "TERM " << N << " IS " 
            << ans.first << "/" << ans.second << "\n";
    }

    return 0;
}

Pii GetNthFraction(int N) {
    Pii ans;
    int line = 0;
    int end = 0;
    int diff;
    int top, bottom;

    while (N > end) {
        line++;
        end += line;
    }

    diff = end - N;

    top = line - diff;
    bottom = diff + 1;
    
    if (line & 1) {
        swap(top, bottom);
    }

    ans = { top,bottom };

    return ans;
};