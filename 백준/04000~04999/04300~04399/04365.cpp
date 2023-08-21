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

Words FillPokers();
void ShowPokers(Words& pokers, vector<vector<int>>& shuffles, int N);
void ShufflePokers(Words& pokers, vector<vector<int>>& shuffles, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words pokers = FillPokers();
    vector<vector<int>> shuffles;
    vector<int> shuffle;
    int TC, index, N;

    cin >> TC;

    while (TC--) {
        for (int i = 0; i < 52; i++) {
            cin >> index;
            shuffle.push_back(index - 1);
        }
        shuffles.push_back(shuffle);
        shuffle.clear();
    }

    while (cin >> N) {
        ShowPokers(pokers, shuffles, N);
        ShufflePokers(pokers, shuffles, N);
    }

    return 0;
}

Words FillPokers() {
    Words pokers;
    MapiS number = {
        {0,"2"},{1,"3"},{2,"4"},{3,"5"},{4,"6"},
        {5,"7"},{6,"8"},{7,"9"},{8,"10"},
        {9,"Jack"},{10,"Queen"},{11,"King"},{12,"Ace"}
    };
    MapiS pattern = {
        {0,"Clubs"},
        {1,"Diamonds"},
        {2,"Hearts"},
        {3,"Spades"},
    };
    string card;

    for (int i = 0; i < 52; i++) {
        card = number[i % 13] + " of " + pattern[i / 13];
        pokers.push_back(card);
    }

    return pokers;
};

void ShowPokers(Words& pokers, vector<vector<int>>& shuffles, int N) {
    vector<int> shuffle = shuffles[N - 1];
    for (int index : shuffle) {
        cout << pokers[index] << "\n";
    }
    cout << "\n";
};

void ShufflePokers(Words& pokers, vector<vector<int>>& shuffles, int N) {
    Words new_pokers;
    vector<int> shuffle = shuffles[N - 1];

    for (int index : shuffle) {
        new_pokers.push_back(pokers[index]);
    }

    pokers = new_pokers;
};