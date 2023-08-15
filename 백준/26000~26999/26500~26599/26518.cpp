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

double GetLimit(LL b, LL c);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL a1, a2;
    LL b, c;

    cin >> b >> c >> a1 >> a2;

    cout.precision(10);
    cout << fixed;
    cout << GetLimit(b, c) << "\n";

    return 0;
}

double GetLimit(LL b, LL c) {
    double L = (b + sqrt(b * b + 4 * c)) / 2;
    return L;
};