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

Pii CalcMaxRollcakeNum(vector<Pii>& ranges, int L, int N);
int FindMaxIndex(vector<int>& counts);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> ranges;
    Pii range, answer;;
    int L, N;
    
    cin >> L >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> range.first >> range.second;
        ranges.push_back(range);
    }

    answer = CalcMaxRollcakeNum(ranges, L, N);

    cout << answer.first << "\n"
        << answer.second << "\n";

    return 0;
}

Pii CalcMaxRollcakeNum(vector<Pii>& ranges, int L, int N) {
    vector<int> rollcake(L + 1, 0), counts(N + 1, 0);
    Pii answer;
    int maxRollcake = -1;
    int curRollcake;
    int start, end;

    for (int i = 0; i < N; i++) {
        start = ranges[i].first;
        end = ranges[i].second;
        curRollcake = end - start + 1;

        if (curRollcake > maxRollcake) {
            maxRollcake = curRollcake;
            answer.first = i + 1;
        }

        for (int j = start; j <= end; j++) {
            if (rollcake[j]) {
                continue;
            }
            rollcake[j] = i + 1;
            counts[i + 1]++;
        }
    }

    answer.second = FindMaxIndex(counts);

    return answer;
};

int FindMaxIndex(vector<int>& counts) {
    auto it = max_element(counts.begin(), counts.end());

    return distance(counts.begin(), it);
};