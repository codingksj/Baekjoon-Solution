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
#include<tuple>
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
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;

bitset<11> FillCayaks(int N);
int CalcMinTeam(bitset<11>& cayaks, int N, int S, int R);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bitset<11> cayaks;
    int N, S, R;
    int ans;

    cin >> N >> S >> R;

    cayaks = FillCayaks(N);

    ans = CalcMinTeam(cayaks, N, S, R);

    cout << ans;

    return 0;
}

bitset<11> FillCayaks(int N) {
    bitset<11> cayaks = (1 << N + 1) - 2;

    return cayaks;
};

int CalcMinTeam(bitset<11>& cayaks, int N, int S, int R) {
    bitset<11> cayaks_copy = cayaks;
    vector<int> repairNums;
    int teamNumber;
    int pTeam, nTeam;

    for (int i = 0; i < S; i++) {
        cin >> teamNumber;
        cayaks_copy[teamNumber] = 0;
    }

    for (int i = 0; i < R; i++) {
        cin >> teamNumber;
        if (cayaks_copy[teamNumber]) {
            repairNums.push_back(teamNumber);
            continue;
        }
        cayaks_copy[teamNumber] = 1;
    }

    sort(repairNums.begin(), repairNums.end());

    for (int r : repairNums) {
        if (r == 1) {
            if (!cayaks_copy[r + 1]) {
                cayaks_copy[r + 1] = 1;
            }
        }
        else if (r == N) {
            if (!cayaks_copy[r - 1]) {
                cayaks_copy[r - 1] = 1;
            }
        }
        else {
            if (!cayaks_copy[r - 1]) {
                cayaks_copy[r - 1] = 1;
                continue;
            }
            if (!cayaks_copy[r + 1]) {
                cayaks_copy[r + 1] = 1;
            }
        }
    }

    pTeam = cayaks_copy.count();
    nTeam = N - pTeam;

    return nTeam;
};