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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2Di;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    double d, f;
    double pd, pf;
    double totalD, totalF;
    int ans;

    while (cin >> d >> f) {
        if (d == -1 && f == -1) {
            break;
        }

        pd = d;
        pf = f;
        totalD = totalF = 0;

        while (cin >> d >> f) {
            if (d == 0 && f == 0) {
                break;
            }
            if (f < pf) {
                totalD += d - pd;
                totalF += pf - f;
            }
            pd = d;
            pf = f;
        }
        ans = round(pf * totalD / totalF);

        cout << ans << "\n";
    }

    return 0;
}
