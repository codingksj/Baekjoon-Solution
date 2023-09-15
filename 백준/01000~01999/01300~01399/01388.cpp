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

int CountPlank(const Words& floor, const int R, const int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words floor;
    int R, C;
    int count;

    cin >> R >> C;

    floor.resize(R);

    for (string& row : floor) {
        cin >> row;
    }

    count = CountPlank(floor, R, C);

    cout << count << "\n";

    return 0;
}

int CountPlank(const Words& floor, const int R, const int C) {
    int length, count = 0;

    for (int r = 0; r < R; r++) {
        length = 0;
        for (int c = 0; c < C; c++) {
            if (floor[r][c] == '-') {
                length++;
                continue;
            }
            (length > 0) && count++;
            length = 0;
        }
        (length > 0) && count++;
    }

    for (int c = 0; c < C; c++) {
        length = 0;
        for (int r = 0; r < R; r++) {
            if (floor[r][c] == '|') {
                length++;
                continue;
            }
            (length > 0) && count++;
            length = 0;
        }
        (length > 0) && count++;
    }

    return count;
};