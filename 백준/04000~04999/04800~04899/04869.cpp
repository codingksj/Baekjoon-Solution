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

double CalcProbablity(char dealer, char myCard1, char myCard2, int n);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    char dealer, myCard1, myCard2;
    double probablity;
    int N;

    while (cin >> N) {
        if (N == 0) {
            break;
        }
        cin >> dealer >> myCard1 >> myCard2;
        probablity = CalcProbablity(dealer, myCard1, myCard2, N);

        cout << setprecision(3) << fixed << probablity << "%" << "\n";
    }

    return 0;
}

double CalcProbablity(char dealer, char myCard1, char myCard2, int n) {
    map<char, int> table = {
        {'A',11},
        {'2',2},{'3',3},{'4',4},
        {'5',5},{'6',6},{'7',7},
        {'8',8},{'9',9},{'T',10},
        {'J',10},{'Q',10},{'K',10},
    };    
    map<char, int> cards = {
        {'A',4*n},
        {'2',4*n},{'3',4*n},{'4',4*n},
        {'5',4*n},{'6',4*n},{'7',4*n},
        {'8',4*n},{'9',4*n},{'T',4*n},
        {'J',4*n},{'Q',4*n},{'K',4*n},
    };

    int totalCards = 52 * n - 3;
    int possibleWin = 0;
    int sumMe = table[myCard1] + table[myCard2];
    int dealerVal1 = table[dealer];
    int dealerVal2;
    int sumDealer;
    double probablity;

    cards[dealer]--;
    cards[myCard1]--;
    cards[myCard2]--;

    if (sumMe == 22) {
        sumMe = 12;
    }

    for (const pair<char, int>& p : cards) {
        dealerVal2 = table[p.first];
        sumDealer = dealerVal1 + dealerVal2;
        if (sumDealer == 22) {
            sumDealer = 12;
        }
        if (sumDealer < sumMe) {
            possibleWin += p.second;
        }
    }

    probablity = double(possibleWin * 100) / totalCards;

    return probablity;
};
