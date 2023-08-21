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
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

vector<Pii> CalcWinRate(int N, int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> rsps;
    double avg;
    int N, K;

    while (true) {
        cin >> N;

        if (N == 0) {
            break;
        }

        cin >> K;

        rsps = CalcWinRate(N, K);

        for (int i = 1; i <= N; i++) {
            if (rsps[i].second) {
                avg = double(rsps[i].first) / rsps[i].second + 1E-7;
                cout << fixed << setprecision(3) << avg << "\n";
            }
            else {
                cout << "-" << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}

vector<Pii> CalcWinRate(int N, int K) {
    vector<Pii> rsps(N + 1, { 0,0 });
    string hand1, hand2;
    bool win;
    int total = K * N * (N - 1) / 2;
    int p1, p2;

    for (int i = 0; i < total; i++) {
        cin >> p1 >> hand1 >> p2 >> hand2;

        if (hand1 == hand2) {
            continue;
        }

        win = (hand1[0] == 'r' && hand2[0] == 's') ||
            (hand1[0] == 's' && hand2[0] == 'p') ||
            (hand1[0] == 'p' && hand2[0] == 'r');

        win ? rsps[p1].first++ : rsps[p2].first++;
        rsps[p1].second++;
        rsps[p2].second++;
    }
    return rsps;
};