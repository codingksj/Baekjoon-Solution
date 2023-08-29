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

typedef struct Player {
    vector<int> cards;
    int index;
    int best;

    bool operator<(const Player& other) const{
        if (best != other.best) {
            return best > other.best;
        }
        return index > other.index;
    }
}Player;

vector<Player> GetPlayers(int N);
int FindWinner(vector<Player>& players);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Player> players;
    int N, winner;

    cin >> N;

    players = GetPlayers(N);
    winner = FindWinner(players);

    cout << winner;

    return 0;
}

vector<Player> GetPlayers(int N) {
    vector<Player> players(N);
    int card;
    int sum;
    int index = 1;
    
    for (Player& player : players) {
        player.index = index++;
        player.best = 0;

        for (int i = 0; i < 5; i++) {
            cin >> card;
            player.cards.push_back(card);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                for (int k = j + 1; k < 5; k++) {
                    sum = (player.cards[i] + player.cards[j] + player.cards[k]) % 10;
                    player.best = max(player.best, sum);
                }
            }
        }
    }

    return players;
};

int FindWinner(vector<Player>& players) {
    vector<Player> copy = players;
    int winner;

    sort(copy.begin(), copy.end());

    winner = copy[0].index;

    return winner;
};