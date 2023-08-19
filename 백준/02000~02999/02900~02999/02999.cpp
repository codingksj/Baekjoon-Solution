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
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

string DecodeMessage(string& message, int& maxL);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string message, decodedMessage;
    int maxL;

    cin >> message;

    maxL = message.length();

    decodedMessage = DecodeMessage(message, maxL);

    cout << decodedMessage;

    return 0;
}

string DecodeMessage(string& message, int& maxL) {
    vector<Pii> RCs;
    Pii best_pair;
    Words subMsgs;
    string subMsg, decodedMsg = "";
    int maxR = 0;
    int R, C;

    for (int i = maxL; i >= 1; i--) {
        if (maxL % i) {
            continue;
        }
        R = maxL / i;
        C = maxL / R;
        RCs.push_back({ R,C });       
    }

    for (Pii& p : RCs) {
        if (p.first <= p.second) {
            best_pair = p;
            continue;
        }
        break;
    }

    R = best_pair.first;
    C = best_pair.second;

    for (int i = 0; i < maxL; i += R) {
        subMsg = message.substr(i, R);
        subMsgs.push_back(subMsg);
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            decodedMsg += subMsgs[c][r];
        }
    }

    return decodedMsg;
};