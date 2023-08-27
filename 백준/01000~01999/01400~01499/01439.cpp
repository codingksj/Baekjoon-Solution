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

int FindMinimumFlip(string& binary);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string binary;
    int ans;

    cin >> binary;

    ans = FindMinimumFlip(binary);

    cout << ans;

    return 0;
};

int FindMinimumFlip(string& binary) {
    int count = 0;
    int maxL = binary.length();
    int count0 = 0;
    int count1 = 0;

    binary[0] == '0' ? count0++ : count1++;

    for (int i = 1; i < maxL; i++) {
        (binary[i] != binary[i - 1]) && (binary[i] == '0' ? count0++ : count1++);
    }

    count = min(count0, count1);

    return count;
};