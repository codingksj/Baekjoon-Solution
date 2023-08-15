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

    set<string> rainbow = {"ChongChong"};
    string p1, p2;
    bool isIncluded;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> p1 >> p2;

        isIncluded = (rainbow.find(p1) != rainbow.end())
            || (rainbow.find(p2) != rainbow.end());

        if (isIncluded) {
            rainbow.insert(p1);
            rainbow.insert(p2);
        }
    }

    cout << rainbow.size();

    return 0;
}
