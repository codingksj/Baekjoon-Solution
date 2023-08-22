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

Pii SimulateMo(vector<int>& moves, int P, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> moves(1002, 0);
    Pii ans;
    int P, N;

    cin >> P >> N;

    for (int i = 0; i < N; i++) {
        cin >> moves[i];
    }

    ans = SimulateMo(moves, P, N);

    cout << ans.first << " " << ans.second;

    return 0;
}

Pii SimulateMo(vector<int>& moves, int P, int N) {
    Pii ans = { 0, 0 };
    vector<char> mo(P + 2, '-');
    char p;
    int cur, other;

    for (int i = 0; i < N; i++) {
        cur = moves[i];
        p = (i & 1) ? 'B' : 'W';
        mo[cur] = p;

        for (other = cur - 1; other >= 1 && !(mo[other] == '-' || mo[other] == p); other--) {};

        if (mo[other] == p && other != cur) {
            fill(mo.begin() + other + 1, mo.begin() + cur, '-');
        }

        for (other = cur + 1; other <= P && !(mo[other] == '-' || mo[other] == p); other++) {};

        if (mo[other] == p && other != cur) {
            fill(mo.begin() + cur + 1, mo.begin() + other, '-');
        }
    }

    for (char c : mo) {
        if (c == 'W') {
            ans.first++;
        }
        else if (c == 'B') {
            ans.second++;
        }
    }

    return ans;
}
