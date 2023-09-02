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
typedef vector<vector<LL>> Matrix2D_L;

string FindSecretMsg(Words& lines);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words lines;
    string line, msg;

    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        else if (line == "*") {
            msg = FindSecretMsg(lines);

            cout << msg << "\n";

            lines.clear();
        }
        else {
            lines.push_back(line);
        }
    }

    return 0;
}

string FindSecretMsg(Words& lines) {
    string msg = "", s;
    bitset<5> binary;
    int blank, padding, val;
    int maxL;

    for (string& line : lines) {
        blank = 0;

        for (char& ch : line) {
            if (ch == ' ') {
                blank++;
            }
            else if (blank > 0) {
                s += to_string(!(blank & 1));
                blank = 0;
            }
        }
    }

    padding = (5 - s.length() % 5) % 5;
    s += string(padding, '0');
    maxL = s.length();

    for (int i = 0; i < maxL; i += 5) {
        binary = bitset<5>(s.substr(i, 5));
        val = binary.to_ulong();
        msg += " ABCDEFGHIJKLMNOPQRSTUVWXYZ',-.?"[val];
    }

    return msg;
};