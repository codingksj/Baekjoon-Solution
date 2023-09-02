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
typedef vector<vector<LL>> Matrix2D_L;

bool CheckValid(string& pw);
bool CheckVowel(string& pw);
bool CheckContinuous(string& pw);
bool CheckSameLetter(string& pw);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string password;
    bool isValid;

    while (cin >> password) {
        if (password == "end") {
            break;
        }

        isValid = CheckValid(password);

        cout << "<" << password << ">" << " is " 
            << (isValid ? "" : "not ") << "acceptable." << "\n";
    }

    return 0;
}

bool CheckValid(string& pw) {
    bool hasVowel = CheckVowel(pw);
    bool isContinuous = CheckContinuous(pw);
    bool hasSameLetter = CheckSameLetter(pw);
    bool isValid = hasVowel && !isContinuous && !hasSameLetter;

    return isValid;
};
bool CheckVowel(string& pw) {
    for (char ch : pw) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
    }
    return false;
};
bool CheckContinuous(string& pw) {
    bool isVowel;
    int cCount = 0;
    int vCount = 0;
    int maxL = pw.length();

    for (char ch : pw) {
        isVowel = ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';

        if (isVowel) {
            cCount = 0;
            vCount++;
        }
        else {
            vCount = 0;
            cCount++;
        }
        if (vCount > 2 || cCount > 2) {
            return true;
        }
    }

    return false;
};
bool CheckSameLetter(string& pw) {
    char prev = pw[0], cur;
    int maxL = pw.length();

    for (int i = 1; i < maxL; i++) {
        cur = pw[i];
        if (prev == cur && !(cur == 'e' || cur == 'o')) {
            return true;
        }
        prev = cur;
    }

    return false;
};