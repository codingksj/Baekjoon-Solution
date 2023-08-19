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

    vector<int> mushrooms(10,0), sums(10,0);
    int delta, minDelta = 1E+6;
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < 10; i++) {
        cin >> mushrooms[i];
        sum += mushrooms[i];
        sums[i] = sum;
    }

    for (int sum : sums) {
        delta = abs(100 - sum);
        if (delta <= minDelta && sum > ans) {
            minDelta = delta;
            ans = sum;
            continue;
        }
    }

    cout << ans;

    return 0;
}

