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

    vector<char> answer;
    unordered_map<char, bool> table = {
        {'a',true},
        {'e',true},
        {'i',true},
        {'o',true},
        {'u',true}
    };
    string line;
    int maxL;

    getline(cin, line);

    maxL = line.length();

    for (int i = 0; i < maxL; i++) {
        cout << line[i];
        if (table[line[i]]) {
            i += 2;
        }
    }

    return 0;
}
