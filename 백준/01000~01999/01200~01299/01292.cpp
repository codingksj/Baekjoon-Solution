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
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;

LL CalcSumOfRange(LL start, LL end);
LL GetCurrentNum(LL index);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL start, end;

    cin >> start >> end;
    cout << CalcSumOfRange(start, end);

    return 0;
}

LL CalcSumOfRange(LL start, LL end) {
    LL sum = 0;
    for (LL i = start; i <= end; i++) {
        sum += GetCurrentNum(i);
    }
    return sum;
};

LL GetCurrentNum(LL index) {
    LL N = 1;
    while (index > N * (N + 1) / 2) {
        N++;
    }
    return N;
};