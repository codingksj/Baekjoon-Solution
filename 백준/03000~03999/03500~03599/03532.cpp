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
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

int CalcMaxDiff(const vector<int>& V, const int limit);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> X, Y;
    int W, H, N;
    int dx, dy;
    int unprotectedArea;

    cin >> W >> H >> N;

    X.resize(N);
    Y.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    dx = CalcMaxDiff(X, W);
    dy = CalcMaxDiff(Y, H);

    unprotectedArea = dx * dy;

    cout << unprotectedArea << "\n";

    return 0;
}

int CalcMaxDiff(const vector<int>& V, const int limit) {
    int prev = 0;
    int maxDiff = 0;

    for (const int& e : V) {
        maxDiff = max(maxDiff, e - prev - 1);
        prev = e;
    }

    maxDiff = max(maxDiff, limit - prev);

    return maxDiff;
}