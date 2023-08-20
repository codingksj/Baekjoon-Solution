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

int CalcTotalCallingFee(vector<Psi>& timesets);


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Psi> timesets;
    Psi timeset;
    int TC;
    int totalFee;

    cin >> TC;

    while (TC--) {
        cin >> timeset.first >> timeset.second;
        timesets.push_back(timeset);
    };

    totalFee = CalcTotalCallingFee(timesets);
    
    cout << totalFee;

    return 0;
}
int CalcTotalCallingFee(vector<Psi>& timesets) {
    int totalFee = 0;
    int hour, min;
    int count, maxCount;

    for (Psi& timeset : timesets) {
        hour = stoi(timeset.first.substr(0, 2));
        min = stoi(timeset.first.substr(3, 2));

        count = 0;
        maxCount = timeset.second;

        while (count < maxCount) {
            totalFee += (hour < 19 && hour >= 7) ? 10 : 5;
            min++;
            if (min == 60) {
                min = 0;
                hour += 1;
                if (hour == 24) {
                    hour = 0;
                }
            }
            count++;
        }
    }
    return totalFee;
};