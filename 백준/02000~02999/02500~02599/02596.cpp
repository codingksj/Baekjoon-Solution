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
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

string InterpretText(string& text, int& N);
char InterpretByte(string& text);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string text, ans;
    int N;

    cin >> N;
    cin >> text;

    ans = InterpretText(text, N);

    cout << ans << "\n";

    return 0;
}

string InterpretText(string& text, int& N) {
    string subText;
    string answerText = "";
    char c;

    for (int i = 0; i < 6 * N; i += 6) {
        subText = text.substr(i, 6);
        c = InterpretByte(subText);
        if (c == '?') {
            answerText = to_string(i / 6 + 1);
            break;
        }
        answerText += c;
    }

    return answerText;
};

char InterpretByte(string& text) {
    vector<pair<char, string>> table = {
        {'A', "000000"},
        {'B', "001111"},
        {'C', "010011"},
        {'D', "011100"},
        {'E', "100110"},
        {'F', "101001"},
        {'G', "110101"},
        {'H', "111010"}
    };
    vector<int> differences;
    int count;
    char c = '?';

    for (pair<char, string>& p : table) {
        count = 0;
        for (int i = 0; i < 6; i++) {
            (p.second[i] != text[i]) && count++;
        }
        differences.push_back(count);
    }

    for (int i = 0; i < 8; i++) {
        if (differences[i] < 2) {
            c = table[i].first;
            break;
        }
    }
    return c;
};
