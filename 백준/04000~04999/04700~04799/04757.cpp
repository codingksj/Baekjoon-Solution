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
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2Di;

typedef struct Team {
    string name;
    int penalty;
    int solved;

    bool operator> (const Team& other) const {
        if (solved != other.solved) {
            return solved > other.solved;
        }
        if (penalty != other.penalty) {
            return penalty < other.penalty;
        }
        return false;
    }
}Team;

vector<Team> GetTeams(int N);
Team FindWinnerTeam(vector<Team>& teams);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Team> teams;
    Team winner;
    int N;

    cin >> N;

    teams = GetTeams(N);
    winner = FindWinnerTeam(teams);

    cout << winner.name << ' ' << winner.solved << ' ' << winner.penalty << '\n';

    return 0;
}

vector<Team> GetTeams(int N) {
    vector<Team> teams(N);
    int submit, time;

    for (int i = 0; i < N; i++) {
        cin >> teams[i].name;

        for (int j = 0; j < 4; j++) {
            cin >> submit >> time;
            if (time > 0) {
                teams[i].solved++;
                teams[i].penalty += (time + (submit - 1) * 20);
            }
        }
    }

    return teams;
};

Team FindWinnerTeam(vector<Team>& teams) {
    Team winner;

    sort(teams.begin(), teams.end(), greater<Team>());

    winner = teams[0];

    return winner;
};