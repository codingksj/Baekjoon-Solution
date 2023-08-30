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

typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

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

Words MakeFrame(char& alpha, char& pattern);
Words MakeDecoration(string& word);
Words AttachFrame(Words& decoration, char& alpha, char& pattern, int& pos);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words decoration;
    string word;

    cin >> word;

    decoration = MakeDecoration(word);

    for (string& line : decoration) {
        cout << line << "\n";
    }

    return 0;
}

Words MakeFrame(char& alpha, char& pattern) {
    Words frame(5, string(5, '.'));
    int sum;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            sum = r + c;
            if (sum == 2 || sum == 6) {
                frame[r][c] = pattern;
            }
            else if (sum == 4 && r*c) {
                frame[r][c] = (r == 2 && c == 2) ? alpha : pattern;
            }
        }
    }

    return frame;
};

Words MakeDecoration(string& word) {
    Words decoration;
    char alpha, pattern;
    int maxL = word.length();
    int decoL = 5 + 4 * (maxL - 1);
    int pos;

    decoration.resize(5, string(decoL, '.'));

    for (int i = 0; i < maxL; i++) {
        pos = 4 * i;
        alpha = word[i];
        pattern = (i % 3 == 2) ? '*' : '#';
        decoration = AttachFrame(decoration, alpha, pattern, pos);
    }

    return decoration;
};

Words AttachFrame(Words& decoration, char& alpha, char& pattern, int& pos) {
    Words deco_copy = decoration;
    Words frame = MakeFrame(alpha, pattern);
    bool canOverwrite;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            canOverwrite = deco_copy[r][c + pos] != '*';
            if (canOverwrite) {
                deco_copy[r][c + pos] = frame[r][c];
            }
        }
    }

    return deco_copy;
};