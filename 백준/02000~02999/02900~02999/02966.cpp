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

    vector<string> patterns = {
        "ABC",
        "BABC",
        "CCAABB"
    };
    vector<string> ID = {
        "Adrian",
        "Bruno",
        "Goran"
    };
    string problems;
    int scores[] = { 0,0,0 };
    int N, length, maxL, maxSize;
    int max = -1;

    cin >> N >> problems;

    maxL = problems.length();
    maxSize = patterns.size();

    for (string& s : patterns) {
        length = s.length();
        while (!(length > maxL)) {
            s += s;
            length = s.length();
        }
    }
    for (int length = 0; length < maxL; length++) {
        for (int i = 0; i < maxSize; i++) {
            (patterns[i][length] == problems[length]) && scores[i]++;
        }
    }
    max = *max_element(scores, scores + sizeof(scores) / sizeof(int));

    cout << max << "\n";
    for (int i = 0; i < maxSize; i++) {
        (scores[i] == max) && (cout << ID[i] << "\n");
    }
    return 0;
}
