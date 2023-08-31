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

MapSi GetGameInfo();
string FindWinner(MapSi& gameInfo);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    MapSi gameInfo;
    string winner;
    int TC;

    cin >> TC;
    cin.ignore();

    while (TC--) {
        gameInfo = GetGameInfo();
        winner = FindWinner(gameInfo);

        cout << winner << "\n";
    }

    return 0;
}

MapSi GetGameInfo() {
    MapSi gameInfo;
    string T1, T2;
    int score1, score2;

    for (int i = 0; i < 16; i++) {
        cin >> T1 >> T2 >> score1 >> score2;

        cin.ignore();

        gameInfo[T1] += (score1 > score2);
        gameInfo[T2] += (score1 < score2);
    }

    return gameInfo;
};

string FindWinner(MapSi& gameInfo) {
    string winner;
    
    for (pair<const string, int>& p : gameInfo) {
        if (p.second == 4) {
            winner = p.first;
            break;
        }
    }

    return winner;
};