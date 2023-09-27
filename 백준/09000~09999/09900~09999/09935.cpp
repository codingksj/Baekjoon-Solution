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

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

string FIndStringAfterExplode(const string& word, const string& bomb);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string word, bomb;
    string ans;

    getline(cin, word);
    getline(cin, bomb);

    ans = FIndStringAfterExplode(word, bomb);

    cout << ans << "\n";

    return 0;
}

string FIndStringAfterExplode(const string& word, const string& bomb) {
    vector<char> wordStk;
    string ans;
    int bombSize, wordSize;
    bool isBoom;

    bombSize = bomb.length();

    for (const char& c : word) {
        wordStk.push_back(c);
        wordSize = wordStk.size();

        if (wordSize < bombSize) {
            continue;
        }

        isBoom = true;

        for (int i = 0; i < bombSize; i++) {
            if (wordStk[wordSize - bombSize + i] != bomb[i]) {
                isBoom = false;
                break;
            }
        }

        if (!isBoom) {
            continue;
        } 

        for (int i = 0; i < bombSize; i++) {
            wordStk.pop_back();
        }
    }

    ans = string(wordStk.begin(), wordStk.end());

    if (ans == "") {
        ans = "FRULA";
    }

    return ans;
};
