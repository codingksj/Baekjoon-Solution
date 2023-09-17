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

string MakeWord(const int number);
bool Cmp(const int& e1, const int& e2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> V;
    int start, end;

    cin >> start >> end;

    for (int i = start; i <= end; i++) {
        V.push_back(i);
    }

    sort(V.begin(), V.end(), Cmp);

    for (int i = 0; i < end - start + 1; i++) {
        cout << V[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }
}

string MakeWord(const int number) {
    map<char, string> digitMap = {
        {'0', "Zero"},
        {'1', "One"},
        {'2', "Two"},
        {'3', "Three"},
        {'4', "Four"},
        {'5', "Five"},
        {'6', "Six"},
        {'7', "Seven"},
        {'8', "Eight"},
        {'9', "Nine"}
    };
    string strN = to_string(number);
    string numberWord = "";

    for (const char& digit : strN) {
        numberWord += digitMap[digit];
    }

    return numberWord;
};

bool Cmp(const int& e1, const int& e2) {
    string s1 = MakeWord(e1);
    string s2 = MakeWord(e2);

    return s1 < s2;
};