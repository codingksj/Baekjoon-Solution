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
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> condos;
    Pii condo;
    int TC;
    int count = 1;
    int minCost;

    cin >> TC;

    for (int i = 0; i < TC; i++) {
        cin >> condo.first >> condo.second;
        condos.push_back(condo);
    }
    sort(condos.begin(), condos.end());

    minCost = condos[0].second;

    for (int i = 1; i < TC; i++) {
        if (condos[i].second < minCost) {
            minCost = condos[i].second;
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}
