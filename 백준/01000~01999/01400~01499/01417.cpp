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

vector<int> GetCandidates(int N);
int CalcMinBuy(vector<int>& candidates, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> candidates;
    int N, buy;

    cin >> N;

    candidates = GetCandidates(N);
    buy = CalcMinBuy(candidates, N);

    cout << buy;

    return 0;
};

vector<int> GetCandidates(int N) {
    vector<int> candidates(N);

    for (int& candidate : candidates) {
        cin >> candidate;
    }

    return candidates;
};

int CalcMinBuy(vector<int>& candidates, int N) {
    vector<int> copy = candidates;
    int maxVote;
    int dasom = copy[0];
    int buy = 0;
    int index;

    if (N == 1) {
        return 0;
    }
    while (true){
        auto it = max_element(copy.begin() + 1, copy.end());
        maxVote = *it;
        if (dasom > maxVote) {
            break;
        }
        index = distance(copy.begin(), it);
        copy[index]--;
        dasom++;
        buy++;
    }

    return buy;
};