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

Pii CalculateScore(Words& RSP, string& S, int& R, int& N);
int GetScore(char& p1, char& p2);
int GetMaxScore(string& turn);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words RSP;
    Pii result;
    string S, friends;
    
    int R, N;

    cin >> R >> S >> N;

    for (int i = 0; i < N; i++) {
        cin >> friends;
        RSP.push_back(friends);
    }

    result = CalculateScore(RSP, S, R, N);

    cout << result.first << "\n" << result.second << "\n";

    return 0;
}

Pii CalculateScore(Words& RSP, string& S, int& R, int& N) {
    Pii scores = { 0,0 };
    string turn;

    for (int length = 0; length < R; length++) {
        turn = "";
        for (int i = 0; i < N; i++) {
            scores.first += GetScore(S[length], RSP[i][length]);
            turn += RSP[i][length];
        }
        scores.second += GetMaxScore(turn);
    }

    return scores;
};

int GetScore(char& p1, char& p2) {
    bool win = 
        (p1 == 'R' && p2 == 'S') || 
        (p1 == 'S' && p2 == 'P') ||
        (p1 == 'P' && p2 == 'R');

    int score;

    if (p1 == p2) {
        score = 1;
    }
    else if (win) {
        score = 2;
    }
    else {
        score = 0;
    }

    return score;
};

int GetMaxScore(string& turn) {
    char r = 'R', s = 'S', p = 'P';
    int scoreR = 0, scoreS = 0, scoreP = 0;
    int maxScore;

    for (char player : turn) {
        scoreR += GetScore(r, player);
        scoreS += GetScore(s, player);
        scoreP += GetScore(p, player);
    }
    maxScore = max({ scoreR,scoreS,scoreP });

    return maxScore;
};