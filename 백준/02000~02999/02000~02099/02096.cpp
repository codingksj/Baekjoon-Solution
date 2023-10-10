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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

Pii CalcMinMax(const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Pii ans;
    int N;

    cin >> N;

    ans = CalcMinMax(N);

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

Pii CalcMinMax(const int N) {
    Pii ans;
    vector<int> scores(3, 0), minScores(3, 0), maxScores(3, 0), tmp(3, 0);

    for (int i = 0; i < N; i++) {
        for (int& score : scores) {
            cin >> score;
        }
        tmp = minScores;
        minScores[0] = min(tmp[0], tmp[1]) + scores[0];
        minScores[2] = min(tmp[1], tmp[2]) + scores[2];
        minScores[1] = min({ tmp[0], tmp[1], tmp[2] }) + scores[1];

        tmp = maxScores;
        maxScores[0] = max(tmp[0], tmp[1]) + scores[0];
        maxScores[2] = max(tmp[1], tmp[2]) + scores[2];
        maxScores[1] = max({ tmp[0], tmp[1], tmp[2] }) + scores[1];
    }

    ans.first = max({ maxScores[0], maxScores[1], maxScores[2] });
    ans.second = min({ minScores[0], minScores[1], minScores[2] });

    return ans;
};