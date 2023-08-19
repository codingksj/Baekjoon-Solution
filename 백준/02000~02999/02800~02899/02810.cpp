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
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

int FindMaximumCupHolder(string& chairs, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string chairs;
    int N, count;

    cin >> N;
    cin >> chairs;

    count = FindMaximumCupHolder(chairs, N);

    cout << count;

    return 0;
}

int FindMaximumCupHolder(string& chairs, int N) {
    int maxL;
    int count;

    while (true) {
        int index = chairs.find("LL");
        if (chairs.find("LL") != string::npos) {
            chairs.replace(index, 2, "-");
            continue;
        }
        break;
    }

    maxL = chairs.length();
    count = (chairs.find("-") != string::npos) ? maxL + 1 : maxL;

    return count;
};