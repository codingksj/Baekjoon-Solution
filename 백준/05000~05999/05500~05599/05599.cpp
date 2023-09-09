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

vector<int> ShuffleDeck(vector<int>& deck, vector<int>& commands, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> deck, shuffledDeck, commands;
    int N, M;
    int command;

    cin >> N >> M;

    for (int i = 1; i <= 2 * N; i++) {
        deck.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> command;
        commands.push_back(command);
    }

    shuffledDeck = ShuffleDeck(deck, commands, N);

    for (int& card : shuffledDeck) {
        cout << card << "\n";
    }

    return 0;
}

vector<int> ShuffleDeck(vector<int>& deck, vector<int>& commands, int N) {
    vector<int> partA, partB;
    vector<int> D = deck;

    for (int& command : commands) {
        if (command == 0) {
            partA = vector<int>(D.begin(), D.begin() + N);
            partB = vector<int>(D.begin() + N, D.end());
            for (int i = 0; i < N; i++) {
                D[2 * i] = partA[i];
                D[2 * i + 1] = partB[i];
            }
        }
        else {
            partA = vector<int>(D.begin(), D.begin() + command);
            partB = vector<int>(D.begin() + command, D.end());
            D.clear();
            for (int& e : partB) {
                D.push_back(e);
            }
            for (int& e : partA) {
                D.push_back(e);
            }
        }
    }
    
    return D;
};