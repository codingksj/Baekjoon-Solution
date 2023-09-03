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

int FindNValue(string& name, int N);
Words MakeSubstr(string& name, int N);
int FindMaxConsecutiveConsonants(string& name);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string name;
    int TC, N, cnt;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> name >> N;

        cnt = FindNValue(name, N);

        cout << "Case #" << i << ": " << cnt << "\n";
    }

    return 0;
}

int FindNValue(string& name, int N) {
    Words substrs = MakeSubstr(name, N);
    int nValue = 0;

    for (string& substr : substrs) {
        if (FindMaxConsecutiveConsonants(substr) >= N) {
            nValue++;
        }
    }

    return nValue;
};

Words MakeSubstr(string& name, int N) {
    Words substrs;
    string s;
    int maxL = name.length();

    for (int i = 0; i <= maxL; i++) {
        for (int j = N; i + j <= maxL; j++) {
            s = name.substr(i, j);
            substrs.push_back(s);
        }
    }

    return substrs;
};

int FindMaxConsecutiveConsonants(string& name) {
    int maxCnt = 0;
    int curCnt = 0;

    for (char ch : name) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            maxCnt = max(maxCnt, curCnt);
            curCnt = 0;
            continue;
        }
        curCnt++;
    }

    maxCnt = max(maxCnt, curCnt);

    return maxCnt;
};