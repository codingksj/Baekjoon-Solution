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

string EncryptWithCaesarRule(const string& pText, const int push);
char MoveAlpha(const char& ch, const int push);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string pText, cipher;
    int push, length;

    cin >> push >> length;
    cin.ignore();

    getline(cin, pText);

    cipher = EncryptWithCaesarRule(pText, push);

    cout << cipher << "\n";

    return 0;
}

string EncryptWithCaesarRule(const string& pText, const int push) {
    string cipher = "";

    if (push % 26) {
        for (const char& ch : pText) {
            cipher += (isalpha(ch) ? MoveAlpha(ch, push) : ch);
        }
    }
    else {
        cipher = pText;
    }
   
    return cipher;
};

char MoveAlpha(const char& ch, const int push) {
    char movedCh;
    int k = push % 26;
    int delta = (ch >= 'a') ? (ch - 'a') : (ch - 'A');

    movedCh = ch - delta + (delta + k) % 26;

    return movedCh;
};