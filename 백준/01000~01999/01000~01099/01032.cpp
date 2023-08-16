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

string FindSamePattern(vector<string>& files, int size, int wordLength);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> files;
    string file, pattern;
    int N, wordLength;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> file;
        files.push_back(file);
    }
    wordLength = files[0].length();
    pattern = FindSamePattern(files, N, wordLength);
    cout << pattern;
    return 0;
}

string FindSamePattern(vector<string>& files, int size, int wordLength) {
    string pattern = "";
    string now, next;
    bool isSame;
    for (int length = 0; length < wordLength; length++) {
        isSame = true;
        for (int i = 0; i < size; i++) {
            now = files[i];
            next = files[(i + 1) % size];
            if (now[length] == next[length]) {
                continue;
            }
            isSame = false;
        }
        pattern += isSame ? now[length] : '?';
    }
    return pattern;
};