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
typedef vector<vector<int>> Matrix2D_i;

#define PI 3.141592653589793

vector<int> FillDeck(int N);
Pii FindExchangableCards(vector<int>& deckN, vector<int>& deckM);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> deckN, deckM;
    Pii ans, fail = { -1,-1 };
    int N, M;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        deckN = FillDeck(N);
        deckM = FillDeck(M);

        ans = FindExchangableCards(deckN, deckM);

        (ans != fail) ?
            cout << ans.first << ' ' << ans.second << "\n" : 
            cout << -1 << "\n";
    }

    return 0;
}

vector<int> FillDeck(int N) {
    vector<int> deck(N);

    for (int i = 0; i < N; i++) {
        cin >> deck[i];
    }

    return deck;
};

Pii FindExchangableCards(vector<int>& deckN, vector<int>& deckM) {
    const int MAX_VAL = 1000000;

    Pii ans = { MAX_VAL, MAX_VAL }, cur;
    int sumN = accumulate(deckN.begin(), deckN.end(), 0);
    int sumM = accumulate(deckM.begin(), deckM.end(), 0);
    int costPast = 2*MAX_VAL, costCur;

    for (int N : deckN) {
        for (int M : deckM) {
            if (sumN - N + M != sumM - M + N) {
                continue;
            }

            cur = { N,M };

            costCur = cur.first + cur.second;
            costPast = ans.first + ans.second;

            if (costCur < costPast) {
                ans = cur;
                costPast = costCur;
            }
        }
    }

    if (costPast == 2 * MAX_VAL) {
        ans = { -1,-1 };
    }

    return ans;
};