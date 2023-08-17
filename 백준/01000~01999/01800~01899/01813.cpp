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

int FindHowManyCorrectPropositions(vector<int>& propositions);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> propositions(51, 0);
    int TC;
    int proposition;
    int ans;

    cin >> TC;

    while (TC--) {
        cin >> proposition;
        propositions[proposition]++;
    }

    ans = FindHowManyCorrectPropositions(propositions);

    cout << ans;
    
    return 0;
}

int FindHowManyCorrectPropositions(vector<int>& propositions) {
    for (int i = 50; i >= 0; i--) {
        if (propositions[i] == i) {
            return i;
        }
    }
    return -1;
};