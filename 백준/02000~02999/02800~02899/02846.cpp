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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> heights, deltas;
    int N, H;
    int delta;
    int maxSize = 0, curSize = 0;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> H;
        heights.push_back(H);
    }

    for (int i = 1; i < N; i++) {
        delta = heights[i] - heights[i - 1];
        deltas.push_back(delta);
    }

    for(int delta : deltas){
        if (delta > 0) {
            curSize += delta;
            continue;
        }
        maxSize = max(maxSize, curSize);
        curSize = 0;
    }
    maxSize = max(maxSize, curSize);

    cout << maxSize;

    return 0;
}

