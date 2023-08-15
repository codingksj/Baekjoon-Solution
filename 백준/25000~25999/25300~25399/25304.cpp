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

    LL X, N;
    LL a, b;
    LL sum = 0;

    cin >> X >> N;

    while (N--) {
        cin >> a >> b;
        sum += a * b;
    }
    cout << (sum == X ? "Yes" : "No") << "\n";
    return 0;
}

