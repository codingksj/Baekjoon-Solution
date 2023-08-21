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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL S, F;
    LL s, f, r;
    LL start, end;
    LL time;
    LL leakedWater;
    int TC, N;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> N;
        cin >> S >> F;
        leakedWater = 0;
        while (N--) {
            cin >> s >> f >> r;
            start = max(S, s);
            end = min(F, f);
            time = end - start + 1;
            if (time < 0) {
                continue;
            }
            leakedWater += time * r;
        }
        cout << "Data Set " << i << ":" << "\n"
            << leakedWater << "\n\n";
    }

    return 0;
}