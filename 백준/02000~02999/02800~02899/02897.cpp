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

vector<int> FindMaxParkinglot(Words& P, int& R, int& C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> pCounts;
    Words P;
    string line;
    int R, C;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> line;
        P.push_back(line);
    }

    pCounts = FindMaxParkinglot(P, R, C);

    for (int count : pCounts) {
        cout << count << "\n";
    }

    return 0;
}

vector<int> FindMaxParkinglot(Words& P, int& R, int& C) {
    vector<int> pCounts(5, 0);
    string space;
    bool isBuilding;
    int count = 0;

    for (int r = 0; r < R - 1; r++) {
        for (int c = 0; c < C - 1; c++) {
            space = P[r].substr(c, 2) + P[r + 1].substr(c, 2);
            isBuilding = false;
            count = 0;

            for (char c : space) {
                if (c == '#') {
                    isBuilding = true;
                    break;
                }
                (c == 'X') && count++;
            }
            (!isBuilding) && pCounts[count]++;
        }
    }
    return pCounts;
};
