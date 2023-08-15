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

    vector<string> words;
    string line;
    string word;
    
    while (true) {
        words.clear();
        getline(cin, line);

        if (line == "#") {
            break;
        }

        istringstream iss(line);

        while (iss >> word) {
            reverse(word.begin(), word.end());
            words.push_back(word);
        }

        for (string word : words) {
            cout << word << " ";
        }

        cout << "\n";
    }
    return 0;
}

