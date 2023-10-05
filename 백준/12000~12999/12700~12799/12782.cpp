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

int CalcFriendship(const string& s1, const string& s2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s1, s2;
    int TC, friendship;

    cin >> TC;

    while (TC--) {
        cin >> s1 >> s2;

        friendship = CalcFriendship(s1, s2);

        cout << friendship << "\n";
    }
    
    return 0;
}

int CalcFriendship(const string& s1, const string& s2) {
    int maxL = s1.length();
    int convert01 = 0;
    int convert10 = 0;
    int minCnt;

    for (int i = 0; i < maxL; i++) {
        if (s1[i] == s2[i]) {
            continue;
        }
        (s1[i] == '1') ? convert10++ : convert01++;
    }

    minCnt = max(convert01, convert10);

    return minCnt;
};