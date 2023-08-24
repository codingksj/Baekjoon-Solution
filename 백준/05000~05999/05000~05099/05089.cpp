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

set<string> InitTowns(int N);
int CountUniqueTowns(set<string>& towns);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    set<string> towns;
    int TC = 1;
    int N, count;

    while (cin >> N) {
        if (N == 0) {
            break;
        }
        cin.ignore();
        towns = InitTowns(N);
        count = CountUniqueTowns(towns);

        cout << "Week " << TC++ << " " << count << "\n";
    }

    return 0;
}

set<string> InitTowns(int N) {
    set<string> towns;
    string town;

    for (int i = 0; i < N; i++) {
        getline(cin, town);
        towns.insert(town);
    }

    return towns;
};

int CountUniqueTowns(set<string>& towns) {
    int count = towns.size();

    return count;
};