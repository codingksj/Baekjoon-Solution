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

#define MAX 200000+1

int alphaCountPos[MAX][26];
int alphaCount[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    string word;
    char letter;
    int maxL, pos, count;
    int L, R;
    int TC;

    cin >> word;

    maxL = word.length();

    for (int length = 0; length < maxL; length++) {
        pos = word[length] - 'a';
        alphaCount[pos]++;
        for (int i = 0; i < 26; i++) {
            alphaCountPos[length][i] = alphaCount[i];
        }
    }

    cin >> TC;

    while (TC--) {
        cin >> letter >> L >> R;

        pos = letter - 'a';
        if (L == R) {
            cout << (letter == word[R]) << "\n";
            continue;
        }
        count = L ? 
            alphaCountPos[R][pos] - alphaCountPos[L - 1][pos] :
            alphaCountPos[R][pos];
        cout << count << "\n";
    }
    return 0;
}
