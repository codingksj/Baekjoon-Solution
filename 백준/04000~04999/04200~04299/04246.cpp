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
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

string DecodeMessage(string& cipher, int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string cipher, decodedMsg;
    int R, C;

    while (true) {
        cin >> C;
        if (C == 0) {
            break;
        }
        cin >> cipher;

        decodedMsg = DecodeMessage(cipher, C);

        cout << decodedMsg << '\n';
    }

    return 0;
}

string DecodeMessage(string& cipher, int C) {
    string decodedMsg = "";
    int R = cipher.length() / C;
    int index;

    for (int c = 0; c < C; c++) {
        for (int r = 0; r < R; r++) {
            index = (r & 1) ? C * r + (C - 1 - c) : C * r + c;
            decodedMsg += cipher[index];
        }
    }

    return decodedMsg;
};