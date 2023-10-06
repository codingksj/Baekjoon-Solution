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

map<char, Pii> MakeKeyBoardPos();
int CalcMinTypingTime(const string& word, const char& leftStart, const char& rightStart);
int CalcTaxiDistance(const Pii& p1, const Pii& p2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string word;
    int time;
    char left, right;

    cin >> left >> right;
    cin >> word;

    time = CalcMinTypingTime(word, left, right);

    cout << time << "\n";

    return 0;
}

map<char, Pii> MakeKeyBoardPos() {
    map<char, Pii> keyboard;
    Words qwerty = {
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    };
    Pii cur = { 0,0 };

    for (const string& line : qwerty) {
        for (const char& key : line) {
            keyboard[key] = cur;
            cur.second++;
        }
        cur.first++;
        cur.second = 0;
    }

    return keyboard;
};

int CalcMinTypingTime(const string& word, const char& leftStart, const char& rightStart) {
    map<char, Pii> keyboard = MakeKeyBoardPos();
    string consonants = "qwertasdfgzxcv";
    char left = leftStart, right = rightStart;
    char* cur = &left;
    int time = 0, distance;
    bool isConsonant;

    for (const char& ch : word) {
        isConsonant = (consonants.find(ch) != string::npos);
        cur = isConsonant ? &left : &right;
        distance = CalcTaxiDistance(keyboard[ch], keyboard[*cur]);
        *cur = ch;
        time += (distance + 1);
    }

    return time;
};

int CalcTaxiDistance(const Pii& p1, const Pii& p2) {
    int dr = abs(p1.first - p2.first);
    int dc = abs(p1.second - p2.second);
    int distance = dr + dc;

    return distance;
};