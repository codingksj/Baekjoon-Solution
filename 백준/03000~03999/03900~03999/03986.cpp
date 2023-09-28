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

Words LoadWords(const int N);
int CountGoodWords(const Words& words);
bool CheckIsGoodWord(const string& word);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words words;
    int N, goodWordsCount;

    cin >> N;

    words = LoadWords(N);
    goodWordsCount = CountGoodWords(words);

    cout << goodWordsCount << "\n";

    return 0;
}

Words LoadWords(const int N) {
    Words words(N);

    for (string& word : words) {
        cin >> word;
    }

    return words;
};

int CountGoodWords(const Words& words) {
    int count = 0;

    for (const string& word : words) {
        CheckIsGoodWord(word) && count++;
    }
    
    return count;
};

bool CheckIsGoodWord(const string& word) {
    stack<char> stk;
    bool isGoodWord;

    for (const char& ch : word) {
        if (stk.empty()) {
            stk.push(ch);
            continue;
        }
        if (stk.top() == ch) {
            stk.pop();
            continue;
        }
        stk.push(ch);
    }

    isGoodWord = stk.empty();

    return isGoodWord;
};