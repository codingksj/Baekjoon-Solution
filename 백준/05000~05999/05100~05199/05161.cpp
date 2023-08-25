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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int K, B, D;
    double value[201];
    double sum, ratio;

    cin >> K;

    for (int i = 1; i <= K; i++) {
        sum = 0.0;

        cin >> B >> D;

        for (int j = 1; j <= B; j++) {
            cin >> value[j];
        }
        for (int j = 1; j <= D; j++) {
            value[B + j] = 0;

            for (int k = 1; k <= B + j - 1; k++) {
                cin >> ratio;
                value[B + j] += ratio * value[k];
            }
        }

        for (int j = 1; j <= B + D; j++) {
            cin >> ratio;
            sum += ratio * value[j];
        }

        cout << "Data Set " << i << ":" << "\n";
        cout << fixed << setprecision(2) << sum << "\n\n";
    }
    return 0;
}
