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

vector<int> MakeAlphaCounts(const string& word);
string MakePalindromeName(const vector<int>& alphaCounts);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> alphaCounts;
    string word, palindromeWord;

    cin >> word;

    alphaCounts = MakeAlphaCounts(word);
    palindromeWord = MakePalindromeName(alphaCounts);

    cout << palindromeWord << '\n';

    return 0;
}

vector<int> MakeAlphaCounts(const string& word) {
    vector<int> alphaCounts(26, 0);

    for (const char& ch : word) {
        alphaCounts[ch - 'A']++;
    }

    return alphaCounts;
};

string MakePalindromeName(const vector<int>& alphaCounts) {
    string left, mid, right;
    string part;
    string palindromeWord = "";
    int oddCount = 0;

    for (int i = 0; i < 26; i++) {
        part = string(alphaCounts[i] / 2, ('A' + i));
        left = left + part;
        right = part + right;
        if (alphaCounts[i] & 1) {
            mid += ('A' + i);
            oddCount++;
        }
    }

    palindromeWord = (oddCount > 1) ? "I'm Sorry Hansoo" : (left + mid + right);

    return palindromeWord;
};