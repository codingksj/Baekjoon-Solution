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
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

string ConvertZ(LL x, LL y, string& z);
LL ConvertToDecimal(LL x, LL y, string& z);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string z, ans;
    LL x, y;
    
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> x >> y >> z;

        ans = ConvertZ(x, y, z);

        cout << ans << "\n";
    }

    return 0;
}

string ConvertZ(LL x, LL y, string& z) {
    vector<char> digits;
    string ans = "";
    char c;
    LL bx = x, by = y;
    LL val, R;

    reverse(z.begin(), z.end());

    val = ConvertToDecimal(x, y, z);

    if (val == 0) {
        return "0";
    }

    do {
        R = val % y;
        c = (R < 10) ? char(R + '0') : char(R + 'A' - 10);
        ans += c;
        val /= y;
    } while (val);

    reverse(ans.begin(), ans.end());

    return ans;
};

LL ConvertToDecimal(LL x, LL y, string& z) {
    vector<LL> digits;
    LL decimal = 0;
    LL w = 1;

    for (char c : z) {
        decimal += (c >= '0' && c <= '9') ?
            (c - '0') * w : (c - 'A' + 10) * w;
        w *= x;
    }

    return decimal;
};