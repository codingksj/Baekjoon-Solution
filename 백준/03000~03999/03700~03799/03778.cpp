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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unordered_map<char, int> charCount;
    string word1, word2;
    int TC;
    int distance;

    cin >> TC;
    cin.ignore();

    for (int i = 1; i <= TC; i++) {
        charCount.clear();
        distance = 0;
        getline(cin, word1);
        getline(cin, word2);
        for (char c : word1) {
            charCount[c]++;
        }
        for (char c : word2) {
            charCount[c]--;
        }
        for (pair<const char, int>& p : charCount) {
            distance += abs(p.second);
        }
        cout << "Case #" << i << ": " << distance << "\n";
    }

    return 0;
}

