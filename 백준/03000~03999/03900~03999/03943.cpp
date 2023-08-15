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

    ULL TC, N;
    ULL maxV;

    cin >> TC;

    while (TC--) {
        cin >> N;
        maxV = N;
        while (N != 1) {
            N = (N & 1) ? 3 * N + 1 : N / 2;
            maxV = max(N, maxV);
        }
        cout << maxV << "\n";
    }
    return 0;
}

