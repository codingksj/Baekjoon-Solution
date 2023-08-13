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

bool compare(const pair<string, int>& a, const pair<string, int>& b);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    string S;
    unordered_map<string, int> words;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        //길이 >= M
        if (S.length() >= M) {
            words[S]++;
        }
    }
    vector<pair<string, int>> wordsV(words.begin(), words.end());
    sort(wordsV.begin(), wordsV.end(), compare);
    for (pair<string,int> p : wordsV) {
        cout << p.first << "\n";
    }
    return 0;
}

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    string s1 = a.first, s2 = b.first;
    int n1 = a.second, n2 = b.second;

    //빈도
    if (n1 != n2) {
        return n1 > n2;
    }
    //길이
    if (s1.length() != s2.length()) {
        return s1.length() > s2.length();
    }
    //사전순
    return s1 < s2;
}
