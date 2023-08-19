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
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    double a, b, c;
    double i, j, k;
    double maxCocktail;

    cin >> a >> b >> c;
    cin >> i >> j >> k;

    maxCocktail = min({ a / i, b / j, c / k });

    a -= maxCocktail * i;
    b -= maxCocktail * j;
    c -= maxCocktail * k;

    cout.precision(10);
    cout << fixed;
    cout << a << " " << b << " " << c << "\n";

    return 0;
}

