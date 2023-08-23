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
typedef vector<vector<int>> Matrix2Di;

int CalcMaxClimber(int N, int length, int P[]);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int P[101] = { 0, };
    int N;
    int rope50, rope60, rope70;

    while (cin >> N) {
        if (N == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        rope50 = CalcMaxClimber(N, 50, P);
        rope60 = CalcMaxClimber(N, 60, P);
        rope70 = CalcMaxClimber(N, 70, P);

        cout << rope50 << ' ' << rope60 << ' ' << rope70 << '\n';
    }

    return 0;
}

int CalcMaxClimber(int N, int length, int P[]) {
    int max = *max_element(P, P + N);
    int sum = accumulate(P, P + N, 0);
    int climber = length / max + 1;

    if (climber < 2 || length < 2 * sum) {
        climber = 0;
    }
    return climber;
};