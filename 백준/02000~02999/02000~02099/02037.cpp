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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

int CountTimeToMessage(string& message, int& p, int& w);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string message;
    int p, w;
    int time;

    cin >> p >> w;
    cin.ignore();
    getline(cin, message);

    time = CountTimeToMessage(message, p, w);

    cout << time;

    return 0;
}

int CountTimeToMessage(string& message, int& p, int& w) {
    int time = 0;
    unordered_map<char, char> table;
    table['A'] = table['B'] = table['C'] = 'A';
    table['D'] = table['E'] = table['F'] = 'D';
    table['G'] = table['H'] = table['I'] = 'G';
    table['J'] = table['K'] = table['L'] = 'J';
    table['M'] = table['N'] = table['O'] = 'M';
    table['P'] = table['Q'] = table['R'] = table['S'] = 'P';
    table['T'] = table['U'] = table['V'] = 'T';
    table['W'] = table['X'] = table['Y'] = table['Z'] = 'W';
    table[' '] = ' ';

    char prev = ' ';
    
    for (char c : message) {
        time += (c - table[c] + 1) * p;
        if ((table[prev] == table[c]) && (c != ' ')) {
            time += w;
        }
        prev = c;
    }
    return time;
};
