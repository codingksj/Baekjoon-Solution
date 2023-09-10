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

LL ConvertToDecimal(const string& N, const LL base);
LL FindCorrectValue(const string& N2, const string& N3);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string N2, N3;
    LL ans;

    getline(cin, N2);
    getline(cin, N3);

    ans = FindCorrectValue(N2, N3);

    cout << ans;

    return 0;
}

LL ConvertToDecimal(const string& N, const LL base) {
    LL value = 0;
    LL power = 1;
    int length = N.length();

    for (int i = length - 1; i >= 0; i--) {
        value += (N[i] - '0') * power;
        power *= base;
    }

    return value;
};

LL FindCorrectValue(const string& N2, const string& N3) {
    string copyN2, copyN3a, copyN3b;
    LL digit2, digit3a, digit3b;
    LL d2, d3;
    int bLength = N2.length();
    int tLength = N3.length();

    for (int i = 0; i < bLength; i++) {
        copyN2 = N2;
        d2 = N2[i] - '0';
        copyN2[i] = '0' + ((d2 + 1) % 2);

        for (int j = 0; j < tLength; j++) {
            copyN3a = copyN3b = N3;
            d3 = N3[j] - '0';
            copyN3a[j] = '0' + ((d3 + 1) % 3);
            copyN3b[j] = '0' + ((d3 + 2) % 3);
               
            digit2 = ConvertToDecimal(copyN2, 2);
            digit3a = ConvertToDecimal(copyN3a, 3);
            digit3b = ConvertToDecimal(copyN3b, 3);

            if (digit2 == digit3a || digit2 == digit3b) {
                return digit2;
            }
        }
    }

    return -1;
};