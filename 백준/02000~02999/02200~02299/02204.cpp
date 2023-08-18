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
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

bool Cmp(string& e1, string& e2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words words;
    string word;
    int N;

    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        words.clear();
        while (N--) {
            cin >> word;
            words.push_back(word);
        }
        sort(words.begin(), words.end(), Cmp);
        cout << words[0] << "\n";
    }

    return 0;
}

bool Cmp(string& e1, string& e2) {
    string e1_lower = e1;
    string e2_lower = e2;

    transform(e1_lower.begin(), e1_lower.end(), e1_lower.begin(), ::tolower);
    transform(e2_lower.begin(), e2_lower.end(), e2_lower.begin(), ::tolower);

    return e1_lower < e2_lower;
};