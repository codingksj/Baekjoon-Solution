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

vector<int> MakeIndexes(int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words names;
    string name;
    vector<int> indexes;
    int N;

    for (int TC = 1;;TC++) {
        cin >> N;

        if (N == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            cin >> name;
            names.push_back(name);
        }

        indexes = MakeIndexes(N);

        cout << "SET " << TC << "\n";

        for (int i : indexes) {
            cout << names[i] << "\n";
        }

        names.clear();
    }

    return 0;
}

vector<int> MakeIndexes(int N) {
    vector<int> indexes;

    if (N & 1) {
        for (int i = 0; i < N; i+=2) {
            indexes.push_back(i);
        }
        for (int i = N - 2; i > 0; i -= 2) {
            indexes.push_back(i);
        }
    }
    else {
        for (int i = 0; i < N - 1; i += 2) {
            indexes.push_back(i);
        }
        for (int i = N - 1; i > 0; i -= 2) {
            indexes.push_back(i);
        }
    }
    return indexes;
};