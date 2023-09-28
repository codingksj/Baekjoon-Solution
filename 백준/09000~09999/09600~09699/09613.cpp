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

typedef map<int, int> Mapii;
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
typedef vector<vector<double>> Matrix2D_d;

LL GCD(const LL x, const LL y);
vector<LL> LoadNumbers(const int N);
LL CalcGCDSum(const vector<LL>& V, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> V;
    LL gcdSum;
    int TC, N;

    cin >> TC;

    while (TC--) {
        cin >> N;

        V = LoadNumbers(N);
        gcdSum = CalcGCDSum(V, N);

        cout << gcdSum << "\n";
    }

    return 0;
}

LL GCD(const LL x, const LL y) {
    if (y == 0) {
        return x;
    }
    return GCD(y, x % y);
}

vector<LL> LoadNumbers(const int N) {
    vector<LL> V(N);

    for (LL& e : V) {
        cin >> e;
    }

    return V;
};

LL CalcGCDSum(const vector<LL>& V, const int N) {
    LL gcdSum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            gcdSum += GCD(V[i], V[j]);
        }
    }

    return gcdSum;
};