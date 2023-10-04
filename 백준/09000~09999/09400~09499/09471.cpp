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

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

int FIndPisanoPeriod(const int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int TC, N, M, period;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> N >> M;

        period = FIndPisanoPeriod(M);

        cout << N << " " << period << "\n";
    }

    return 0;
}

int FIndPisanoPeriod(const int M) {
    vector<int> fibo = { 0,1,1 }, newFibo = { 0,1,1 };
    int period = 0;

    while (++period) {
        newFibo[0] = fibo[1];
        newFibo[1] = fibo[2];
        newFibo[2] = (fibo[1] + fibo[2]) % M;
        fibo = newFibo;
        if (fibo[0] == 0 && fibo[1] == 1) {
            break;
        }
    }

    return period;
};

