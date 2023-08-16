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
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;
typedef vector<string> Words;

bool DetermineEugeneNumber(LL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL N;
    bool isEugeneNumber;

    cin >> N;

    isEugeneNumber = DetermineEugeneNumber(N);

    cout << (isEugeneNumber ? "YES" : "NO") << "\n";

    return 0;
}

bool DetermineEugeneNumber(LL N) {
    string eugeneN = to_string(N);
    string sub1, sub2;
    bool isEugeneN = false;
    int maxL = eugeneN.length();
    int p1, p2;

    for (int i = 1; i < maxL; i++) {
        p1 = p2 = 1;
        sub1 = eugeneN.substr(0, i);
        sub2 = eugeneN.substr(i, maxL - i);
        for (char c : sub1) {
            p1 *= (c - '0');
        }
        for (char c : sub2) {
            p2 *= (c - '0');
        }
        if (p1 == p2) {
            isEugeneN = true;
            break;
        }
    }
    return isEugeneN;
};