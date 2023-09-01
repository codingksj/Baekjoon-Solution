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
typedef vector<vector<LL>> Matrix2D_L;

MapSL GetDict(int N);
LL CalcScore(MapSL& dict);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    MapSL dict;
    LL totalScore;
    int N, M;

    cin >> N >> M;
    cin.ignore();

    dict = GetDict(N);

    for (int i = 0; i < M; i++) {
        totalScore = CalcScore(dict);

        cout << totalScore << "\n";
    }

    return 0;
}

MapSL GetDict(int N) {
    MapSL dict;
    string word;
    LL score;

    for (int i = 0; i < N; i++) {
        cin >> word >> score;
        dict[word] = score;
    }

    return dict;
};

LL CalcScore(MapSL& dict) {
    string s;
    LL totalScore = 0;

    while (true) {
        cin >> s;

        if (s == ".") {
            break;
        }

        totalScore += dict[s];
    }

    return totalScore;
};