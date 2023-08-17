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
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

char InterpretDNA(vector<char>& DNA);
char MakeNewBase(char r, char c);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string input;
    vector<char> DNA;
    char base;
    int N;

    cin >> N;
    cin >> input;
    DNA = vector<char>(input.begin(), input.end());

    base = InterpretDNA(DNA);

    cout << base;
    
    return 0;
}

char InterpretDNA(vector<char>& DNA) {
    int index = DNA.size() - 1;
    char baseR, baseC;

    while (index) {
        baseR = DNA[index - 1];
        baseC = DNA[index];
        DNA[index - 1] = MakeNewBase(baseR, baseC);
        index--;
    }
    return DNA[0];
};

char MakeNewBase(char r, char c) {
    bool A, G, C, T;
    
    A = (r == 'A' && c == 'A') ||
        (r == 'A' && c == 'C') ||
        (r == 'G' && c == 'T') ||
        (r == 'C' && c == 'A') ||
        (r == 'T' && c == 'G');

    G = (r == 'A' && c == 'T') ||
        (r == 'G' && c == 'G') ||
        (r == 'C' && c == 'T') ||
        (r == 'T' && c == 'A') ||
        (r == 'T' && c == 'C');

    C = (r == 'A' && c == 'G') ||
        (r == 'G' && c == 'A') ||
        (r == 'C' && c == 'C');

    T = (r == 'G' && c == 'C') ||
        (r == 'C' && c == 'G') ||
        (r == 'T' && c == 'T');

    if (A) {
        return 'A';
    }
    else if (G) {
        return 'G';
    }
    else if (C) {
        return 'C';
    }
    else if (T) {
        return 'T';
    }
    else {
        return ' ';
    }
};