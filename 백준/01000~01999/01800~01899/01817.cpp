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
#include<tuple>
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

typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;

deque<int> FillBoxWithBooks(int N);
int CalcMinimumBox(deque<int>& box, int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    deque<int> box;
    int N, M;
    int ans;

    cin >> N >> M;

    box = FillBoxWithBooks(N);
    ans = CalcMinimumBox(box, M);

    cout << ans << "\n";

    return 0;
};

deque<int> FillBoxWithBooks(int N) {
    deque<int> box;
    int book;

    for (int i = 0; i < N; i++) {
        cin >> book;
        box.push_back(book);
    }

    return box;
};

int CalcMinimumBox(deque<int>& box, int M) {
    deque<int> B = box;
    int cur = 0;
    int cnt = 1;

    if (B.empty()) {
        return 0;
    }

    while (!B.empty()) {
        if (cur + B.front() <= M) {
            cur += B.front();
            B.pop_front();
        }
        else {
            cnt++;
            cur = 0;
        }
    }

    return cnt;
};