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

string FindMinEffortTime(string& time);
int CalcEffort(int keys[]);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string time, ans;

    cin >> time;

    ans = FindMinEffortTime(time);

    cout << ans;

    return 0;
}

string FindMinEffortTime(string& time) {
    Pii best;
    string ans, hour, min;

    int k[4];
    int effort, minEffort = 1E+6;
    int H = stoi(time.substr(0, 2));
    int M = stoi(time.substr(3, 2));

    for (int h = 0; h <100; h++) {
        for (int m = 0; m < 100; m++) {
            if ((h % 24 != H) || (m % 60 != M)) {
                continue;
            }
            k[0] = h / 10;
            k[1] = h % 10;
            k[2] = m / 10;
            k[3] = m % 10;
            effort = CalcEffort(k);
            if (effort < minEffort) {
                minEffort = effort;
                best = { h,m };
            }
        }
    }
    hour = to_string(best.first);
    min = to_string(best.second);

    if (best.first < 10) {
        hour = '0' + hour;
    }
    if (best.second < 10) {
        min = '0' + min;
    }

    ans = hour + ":" + min;

    return ans;
};

int CalcEffort(int keys[]) {
    vector<Pii> keyCoords(10, { 1,3 });
    int effort = 0;
    int distance;
    int dx, dy;

    for (int i = 1; i <= 9; ++i) {
        keyCoords[i] = { (i - 1) % 3, (i - 1) / 3 };
    }

    for (int i = 0; i < 3; i++) {
        dx = abs(keyCoords[keys[i]].first - keyCoords[keys[i + 1]].first);
        dy = abs(keyCoords[keys[i]].second - keyCoords[keys[i + 1]].second);
        distance = dx + dy;
        effort += distance;
    }

    return effort;
};