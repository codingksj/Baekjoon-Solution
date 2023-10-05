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

Matrix2D_L LoadSatisfactions(const int N, const int M);
LL CalcMaxSatisfaction(const Matrix2D_L& members, const int N, const int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_L members;
    LL maxSatisfaction;
    int N, M;

    cin >> N >> M;

    members = LoadSatisfactions(N, M);
    maxSatisfaction = CalcMaxSatisfaction(members, N, M);

    cout << maxSatisfaction << "\n";
    
    return 0;
}

Matrix2D_L LoadSatisfactions(const int N, const int M) {
    Matrix2D_L members(N, vector<LL>(M, 0));

    for (vector<LL>& member : members) {
        for (LL& chicken : member) {
            cin >> chicken;
        }
    }
    
    return members;
};

LL CalcMaxSatisfaction(const Matrix2D_L& members, const int N, const int M) {
    LL sum, maxSum = -1;

    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            for (int k = j + 1; k < M; k++) {
                sum = 0;

                for (int r = 0; r < N; r++) {
                    sum += max({ members[r][i], members[r][j], members[r][k] });
                }

                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
};