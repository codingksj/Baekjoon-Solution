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

deque<int> FillCards(int N);
void PrintCard(deque<int>& cards);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    deque<int> cards;
    int N;

    cin >> N;

    cards = FillCards(N);

    PrintCard(cards);

    return 0;
}

deque<int> FillCards(int N) {
    deque<int> cards;

    for (int i = 1; i <= N; i++) {
        cards.push_back(i);
    }

    return cards;
};

void PrintCard(deque<int>& cards) {
    deque<int> copy = cards;

    while (copy.size()) {
        cout << copy.front() << ' ';

        copy.pop_front();

        if (copy.empty()) {
            break;
        }

        copy.push_back(copy.front());
        copy.pop_front();

        if (copy.empty()) {
            break;
        }
    }
};