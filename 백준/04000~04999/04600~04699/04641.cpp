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

int FindDouble(bitset<101>& check);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bitset<101> check;
    int N;

    while (true) {
        check.reset();

        while (true) {
            cin >> N;

            if (N == 0 || N == -1) {
                break;
            }

            check[N] = 1;
        }

        if (N == -1) {
            break;
        }

        cout << FindDouble(check) << "\n";
    }

    return 0;
}

int FindDouble(bitset<101>& check) {
    int count = 0;
    for (int i = 1; i <= 50; i++) {
        if (check[i] && check[2 * i]) {
            count++;
        }
    }
    return count;
};