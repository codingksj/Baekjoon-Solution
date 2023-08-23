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
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2Di;

unordered_map<string, set<string>> MakeDict();
Words FindWordInDict(unordered_map<string, set<string>>& dict);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unordered_map<string, set<string>> dict;
    Words answer;
    string word;

    dict = MakeDict();

    answer = FindWordInDict(dict);

    if (!answer.empty()) {
        for (string word : answer) {
            cout << word << "\n";
        }
    }

    return 0;
}

unordered_map<string, set<string>> MakeDict() {
    unordered_map<string, set<string>> dict;
    string word, key;

    while (true) {
        cin >> word;
        if (word == "XXXXXX") {
            break;
        }
        key = word;
        sort(key.begin(), key.end());
        dict[key].insert(word);
    }
    return dict;
};

Words FindWordInDict(unordered_map<string, set<string>>& dict) {
    Words answer;
    string key;
    while (true) {
        cin >> key;
        if (key == "XXXXXX") {
            break;
        }
        sort(key.begin(), key.end());
        if (dict[key].empty()) {
            answer.push_back("NOT A VALID WORD");
        }
        else {
            for (string word : dict[key]) {
                answer.push_back(word);
            }
        }
        answer.push_back("******");
    }
    return answer;
};