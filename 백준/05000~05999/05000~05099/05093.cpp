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
typedef vector<vector<int>> Matrix2D_i;

typedef struct Charinfo {
    char letter;
    int firstAppear;
    int appearOrder;
}Charinfo;

#define PI 3.141592653589793

Words GetWords();
Words MakeReplacedWords(Words& words);
string ReplaceDupliactedLetter(string& word);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words words = GetWords();
    Words changed_words;

    changed_words = MakeReplacedWords(words);

    for (string& word : changed_words) {
        cout << word << "\n";
    }

    return 0;
}

Words GetWords() {
    Words words;
    string word;

    while (getline(cin, word)) {
        if (word == "#") {
            break;
        }
        words.push_back(word);
    }

    return words;
};

Words MakeReplacedWords(Words& words) {
    Words changed_words;
    string changed_word;

    for (string& word : words) {
        changed_word = ReplaceDupliactedLetter(word);
        changed_words.push_back(changed_word);
    }

    return changed_words;
};

string ReplaceDupliactedLetter(string& word) {
    vector<int> letterCounts(27, 0);
    vector<Charinfo> charInfo;
    string changed_word = "", replacement = "*?/+!";
    char loweredChar, letter;
    int maxL = word.length();
    int index, findCount = 0;

    for (int i = 0; i < maxL; i++) {
        loweredChar = tolower(word[i]);
        index = loweredChar - 'a';
        letterCounts[index]++;

        if (letterCounts[index] > 1) {
            charInfo.push_back({ loweredChar, i, findCount++ });
            letterCounts[index] = -100;
        }
    }

    for (int i = 0; i < maxL; i++) {
        letter = word[i];
        loweredChar = tolower(letter);

        for (Charinfo p : charInfo) {
            if (loweredChar == p.letter && i >= p.firstAppear) {
                letter = replacement[p.appearOrder];
                break;
            }
        }

        changed_word += letter;
    }

    return changed_word;
}