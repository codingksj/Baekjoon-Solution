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

    unordered_map<string, bool> table = {
        {"i", true},
        {"pa", true},
        {"te", true},
        {"ni", true},
        {"niti", true},
        {"a", true},
        {"ali", true},
        {"nego", true},
        {"no", true},
        {"ili", true}
    };
    vector<string> words;
    string word, answer = "";
    char letter;
    int maxSize;
  

    while (cin >> word) {
        words.push_back(word);
    }

    maxSize = words.size();

    for (int i = 0; i < maxSize; i++) {
        if (table[words[i]] && i!=0) {
            continue;
        }
        letter = words[i][0] + 'A' - 'a';
        answer += letter;
    }

    cout << answer << "\n";

    return 0;
}
