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

typedef struct Pattern {
    Words pattern;
    int R, C;
}Pattern;

Pattern MakePattern(int N, int M);
int FindPattern(Pattern& P, Pattern& map);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Pattern P, map;
    int N, M;
    int TC, count;

    cin >> TC;

    while (TC--) {
        cin >> N >> M;

        P = MakePattern(N, M);

        cin >> N >> M;

        map = MakePattern(N, M);

        count = FindPattern(P, map);

        cout << count << "\n";
    }

    return 0;
}

Pattern MakePattern(int N, int M) {
    Pattern P;
    Words pattern(N, string(M, '-'));
    P.R = N;
    P.C = M;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> pattern[r][c];
        }
    }

    P.pattern = pattern;

    return P;
};

int FindPattern(Pattern& P, Pattern& map) {
    int R = map.R - P.R + 1;
    int C = map.C - P.C + 1;
    int count = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            bool match = true;

            for (int i = 0; i < P.R && match; i++) {
                if (P.pattern[i] != map.pattern[r + i].substr(c, P.C)) {
                    match = false;
                }
            }

            if (match) {
                count++;
            }
        }
    }

    return count;
}
