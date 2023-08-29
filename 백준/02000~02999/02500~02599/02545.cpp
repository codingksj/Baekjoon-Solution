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

vector<LL> GetCake();
LL CalcMaxVolume(vector<LL>& cake, LL cut);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> cake;
    LL TC, cut, maxV;
    
    cin >> TC;

    while (TC--) {
        cake = GetCake();

        cin >> cut;

        maxV = CalcMaxVolume(cake, cut);

        cout << maxV << "\n";
    }

    return 0;
}

vector<LL> GetCake() {
    vector<LL> cake(3);

    for (LL& side : cake) {
        cin >> side;
    }

    return cake;
};

LL CalcMaxVolume(vector<LL>& cake, LL cut) {
    vector<LL> copy = cake;
    LL volume;
    LL s1, s2, s3;
    LL total = copy[0] + copy[1] + copy[2] - cut;

    sort(copy.begin(), copy.end());
    
    s1 = min(total / 3LL, copy[0]);
    total -= s1;
    s2 = min(total / 2LL, copy[1]);
    total -= s2;
    s3 = total;

    volume = s1 * s2 * s3;

    return volume;
};