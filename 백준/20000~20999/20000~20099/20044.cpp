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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
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
typedef vector<vector<double>> Matrix2D_d;

vector<LL> LoadTeams(const int N);
vector<LL> LoadAbilities(const vector<LL>& teams, const int N);
LL FindTeamAbilityMin(const vector<LL>& abilities);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> teams, abilities;
    LL min;
    int N;

    cin >> N;

    teams = LoadTeams(N);
    abilities = LoadAbilities(teams, N);
    min = FindTeamAbilityMin(abilities);

    cout << min << "\n";

    return 0;
}

vector<LL> LoadTeams(const int N) {
    vector<LL> teams(2 * N);

    for (LL& team : teams) {
        cin >> team;
    }

    return teams;
};

vector<LL> LoadAbilities(const vector<LL>& teams, const int N) {
    vector<LL> sortedTeams = teams;
    vector<LL> abilities(N);

    sort(sortedTeams.begin(), sortedTeams.end());

    for (int i = 0; i < N; i++) {
        abilities[i] = sortedTeams[i] + sortedTeams[2 * N - 1 - i];
    }

    return abilities;
};

LL FindTeamAbilityMin(const vector<LL>& abilities) {
    vector<LL> sortedAbilities = abilities;
    LL min;

    sort(sortedAbilities.begin(), sortedAbilities.end());

    min = sortedAbilities[0];

    return min;
};