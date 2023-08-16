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
typedef pair<string, int> Psi;
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;
typedef vector<string> Words;

LL Rev(LL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL X, Y;
    LL ans;

    cin >> X >> Y;

    ans = Rev(Rev(X) + Rev(Y));

    cout << ans;

    return 0;
}

LL Rev(LL N) {
    deque<LL> digits;
    LL num = N;
    LL w = 1;
    LL revN = 0;

    do {
        digits.push_back(num % 10);
        num /= 10;
    } while (num);

    while (!digits.empty()) {
        revN += digits.back() * w;
        digits.pop_back();
        w *= 10;
    }

    return revN;
};