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

ULL CalcDigitLength(const ULL N);
ULL Power(const ULL base, const ULL power);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    ULL N, ans;

    cin >> N;

    ans = CalcDigitLength(N);

    cout << ans;
}

ULL CalcDigitLength(const ULL N) {
    ULL digitLength = 0;
    ULL count;
    ULL nLength = to_string(N).length();

    for (ULL i = nLength; i >= 1; i--) {
        count = min(N, Power(10ULL, i) - 1) - Power(10ULL, i - 1) + 1ULL;
        digitLength += i * count;
    }
    return digitLength;
}

ULL Power(const ULL base, const ULL power) {
    if (power == 0) {
        return 1ULL;
    }
    return base * Power(base, power - 1);
};