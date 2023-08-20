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
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

typedef struct _moniter {
    int rH, rV;
    int sH, sV;
}Moniter;

int CalcCost(Moniter& cli, Moniter& M, int price);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Moniter cli, M, Mflip;
    int TC;
    int w, h;
    int price, c1, c2;
    int minCost = 1E+9;

    cin >> cli.rH >> cli.rV >>
        cli.sH >> cli.sV;

    cin >> TC;

    while (TC--) {
        cin >> M.rH >> M.rV >> M.sH >> M.sV >> price;
        Mflip = { M.rV,M.rH,M.sV,M.sH };

        c1 = CalcCost(cli, M, price);
        c2 = CalcCost(cli, Mflip, price);
        minCost = min({ c1,c2,minCost });
    }

    cout << minCost;

    return 0;
}


int CalcCost(Moniter& cli, Moniter& M, int price) {
    int w, h;
    int cost;

    w = max(ceil((double)cli.rH / M.rH), ceil((double)cli.sH / M.sH));
    h = max(ceil((double)cli.rV / M.rV), ceil((double)cli.sV / M.sV));

    cost = price * w * h;

    return cost;
};