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

bool Cmp(LL& e1, LL& e2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> scores;
    LL score;
    LL N, K;

    cin >> N >> K;

    while (N--) {
        cin >> score;
        scores.push_back(score);
    }

    sort(scores.begin(), scores.end(), Cmp);

    cout << scores[K - 1];

    return 0;
}

bool Cmp(LL& e1, LL& e2) {
    return e1 > e2;
};