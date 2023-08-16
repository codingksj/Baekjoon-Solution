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
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;
typedef vector<string> Words;

string FindWinnerTeam(Words teams, string lightgreen);
int CalcLuckiness(string lightgreen, string team);
bool Cmp(const pair<string, int>& e1, const pair<string, int>& e2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words teams;
    string team, lightgreen, winnerTeam;
    int TC;

    cin >> lightgreen;
    cin >> TC;
    
    while (TC--) {
        cin >> team;
        teams.push_back(team);
    }
    cout << FindWinnerTeam(teams, lightgreen);

    return 0;
}

string FindWinnerTeam(Words teams, string lightgreen) {
    vector<Psi> probablitys;
    string winnerTeam;
    int luckiness;

    for (string team : teams) {
        luckiness = CalcLuckiness(lightgreen, team);
        probablitys.push_back({ team, luckiness });
    }

    sort(probablitys.begin(), probablitys.end(), Cmp);

    winnerTeam = probablitys[0].first;

    return winnerTeam;
};

int CalcLuckiness(string lightgreen, string team) {
    int L = 0, O = 0, V = 0, E = 0;
    int luckiness;

    for (char letter : lightgreen) {
        switch (letter) {
        case 'L':
            L++;
            break;
        case 'O':
            O++;
            break;
        case 'V':
            V++; 
            break;
        case 'E':
            E++; 
            break;
        }
    }
    for (char letter : team) {
        switch (letter) {
        case 'L':
            L++;
            break;
        case 'O':
            O++;
            break;
        case 'V':
            V++;
            break;
        case 'E':
            E++;
            break;
        }
    }
    luckiness = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
    return luckiness;
};

bool Cmp(const pair<string, int>& e1, const pair<string, int>& e2) {
    if (e1.second != e2.second) {
        return e1.second > e2.second;
    }
    return e1.first < e2.first;
}