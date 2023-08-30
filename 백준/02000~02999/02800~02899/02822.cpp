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

vector<Pii> GetScores();
vector<Pii> GetHighScores(vector<Pii>& scores);
bool Cmp(const pair<const int, const int>& e1, const pair<const int, const int>& e2);
int GetSum(vector<Pii>& highScores);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> scores = GetScores();
    vector<Pii> highScores = GetHighScores(scores);
    int totalScore = GetSum(highScores);

    cout << totalScore << "\n";

    for (Pii& p : highScores) {
        cout << p.first << ' ';
    }

    return 0;
}

vector<Pii> GetScores() {
    vector<Pii> scores(8);
    int index = 1;

    for (Pii& p : scores) {
        p.first = index++;
        cin >> p.second;
    }

    return scores;
};

vector<Pii> GetHighScores(vector<Pii>& scores) {
    vector<Pii> highScores = scores;

    sort(highScores.begin(), highScores.end(), Cmp);

    highScores.pop_back();
    highScores.pop_back();
    highScores.pop_back();

    sort(highScores.begin(), highScores.end());

    return highScores;
};

bool Cmp(const pair<const int, const int>& e1, const pair<const int, const int>& e2) {
    return e1.second > e2.second;
};

int GetSum(vector<Pii>& highScores) {
    int sum = 0;

    for (Pii& p : highScores) {
        sum += p.second;
    }

    return sum;
};