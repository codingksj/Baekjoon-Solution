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

LL FindBestPrice(vector<PLL>& products, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<PLL> products;
    LL bestPrice;
    int N;

    cin >> N;

    products.resize(N);

    for (PLL& p : products) {
        cin >> p.first >> p.second;
    }

    bestPrice = FindBestPrice(products, N);

    cout << bestPrice << "\n";

    return 0;
}

LL FindBestPrice(vector<PLL>& products, int N) {
    LL bestPrice = 0;
    LL maxProfit = 0, curProfit, profit;

    sort(products.begin(), products.end());

    for (int i = 0; i < N; i++) {
        curProfit = 0;
        for (int j = i; j < N; j++) {
            profit = products[i].first - products[j].second;
            (profit > 0) && (curProfit += profit);
        }
        if (curProfit > maxProfit) {
            maxProfit = curProfit;
            bestPrice = products[i].first;
        }
    }
    return bestPrice;
}