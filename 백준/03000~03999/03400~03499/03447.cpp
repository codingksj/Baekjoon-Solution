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
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

Words FixBug(Words& codes);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words codes, fixedCodes;
    string line;

    while (getline(cin, line)) {
        codes.push_back(line);
    }
    
    fixedCodes = FixBug(codes);

    for (string line : fixedCodes) {
        cout << line << '\n';
    }

    return 0;
}

Words FixBug(Words& codes) {
    Words copyCodes = codes;
    size_t pos;

    for (string& line : copyCodes) {
        while (true) {
            pos = line.find("BUG");
            if (pos == string::npos) {
                break;
            }
            line.replace(pos, 3, "");
        }
    }

    return copyCodes;
};