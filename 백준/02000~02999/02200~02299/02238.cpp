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

vector<PSi> GetBuyers(int N);
PSi FindWinner(vector<PSi>& buyers, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<PSi> buyers;
    PSi winner;
    int U, N;

    cin >> U >> N;

    buyers = GetBuyers(N);
    winner = FindWinner(buyers, N);

    cout << winner.first << ' ' << winner.second << "\n";

    return 0;
}

vector<PSi> GetBuyers(int N) {
    vector<PSi> buyers(N);

    for (PSi& buyer : buyers) {
        cin >> buyer.first >> buyer.second;
    }

    return buyers;
};

PSi FindWinner(vector<PSi>& buyers, int N) {
    map<int, int> info;
    Pii auction = { 100001, 100001 };
    PSi winner;

    for (PSi& buyer : buyers) {
        info[buyer.second]++;
    }

    for (pair<const int, int>& p : info) {
        if (p.second < auction.second) {
            auction = p;
        }
        else if (p.second == auction.second) {
            auction.first = min(auction.first, p.first);
        }
    }

    for (PSi& buyer : buyers) {
        if (buyer.second == auction.first) {
            winner = buyer;
            break;
        }
    }

    return winner;
};