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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2Di;

string SimulateSpinner(Words& spinners);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words spinners;
    string spinner, answer;

    while (cin >> spinner) {
        spinners.push_back(spinner);
    }

    answer = SimulateSpinner(spinners);

    cout << answer;

    return 0;
}

string SimulateSpinner(Words& spinners) {
    string answer;
    int maxL = spinners[0].length();
    vector<int> d(maxL);

    for (string spinner : spinners) {
        for (int i = 0; i < maxL; i++) {
            d[i] = (d[i] + spinner[i] - '0') % 10;
        }
    }

    for (int i = 0; i < maxL; i++) {
        answer += to_string(d[i]);
    }
    
    return answer;
};