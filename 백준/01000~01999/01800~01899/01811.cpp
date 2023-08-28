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

string CalcScore(string& A, string& G);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string answer, guess;
    string info;

    while (cin >> answer) {
        if (answer == "#") {
            break;
        }
        cin >> guess;

        info = CalcScore(answer, guess);

        cout << info << "\n";
    }

    return 0;
};

string CalcScore(string& A, string& G) {
    string a = A;
    string b = G;
    string info;
    int maxL = G.length();
    int bCount = 0, gCount = 0, wCount = 0;

    for (int i = 0; i < maxL; ++i) {
        if (a[i] == b[i]) {
            ++bCount;
            a[i] = b[i] = '_';
        }
    }

    for (int i = 0; i < maxL; ++i) {
        if (a[i] != '_') {
            if (i && a[i] == b[i - 1]) {
                ++gCount;
                a[i] = b[i - 1] = '_';
            }
            else if (i + 1 < maxL && a[i] == b[i + 1]) {
                ++gCount;
                a[i] = b[i + 1] = '_';
            }
        }
    }

    for (int i = 0; i < maxL; ++i) {
        if (a[i] != '_') {
            for (int j = 0; j < maxL; ++j) {
                if (a[i] == b[j]) {
                    ++wCount;
                    a[i] = b[j] = '_';
                    break;
                }
            }
        }
    }

    info = G + ": " 
        + to_string(bCount) + " black, " 
        + to_string(gCount) + " grey, " 
        + to_string(wCount) + " white";

    return info;
}