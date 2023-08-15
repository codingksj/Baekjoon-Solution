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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL N;
    LL a, b, c;
    LL minSurfaceArea = 1E+10;

    cin >> N;

    for (LL i = 1; i <= sqrt(N); ++i) {
        if (N % i) {
            continue;
        }
        for (LL j = 1; j <= sqrt(N / i); ++j) {
            if (N % (i * j)) {
                continue;
            } 
            LL k = N / (i * j);
            LL surfaceArea = 2 * (i * j + i * k + j * k);
            if (surfaceArea < minSurfaceArea) {
                minSurfaceArea = surfaceArea;
                a = i;
                b = j;
                c = k;
            }
        }
    }

    cout << a << " " << b << " " << c << "\n";

    return 0;
}