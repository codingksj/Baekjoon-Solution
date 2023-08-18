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
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

vector<Psi> FindCoinPattern(string& coins);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Psi> patternCounts;
    string coins;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> coins;
        patternCounts = FindCoinPattern(coins);
        for (Psi& p : patternCounts) {
            cout << p.second << " ";
        }
        cout << "\n";
    }

    return 0;
}

vector<Psi> FindCoinPattern(string& coins) {
    vector<Psi> patternCounts = {
        {"TTT", 0}, {"TTH", 0}, 
        {"THT", 0}, {"THH", 0},
        {"HTT", 0}, {"HTH", 0}, 
        {"HHT", 0}, {"HHH", 0}
    };
    string subCoin;
    int maxL = coins.length() - 2;

    for (int i = 0; i < maxL; i++) {
        subCoin = coins.substr(i, 3);
        for (Psi& p : patternCounts) {
            if (subCoin == p.first) {
                p.second++;
                break;
            }
        }
    }
    return patternCounts;
};