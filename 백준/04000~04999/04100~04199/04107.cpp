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

    vector<int> patterns, stitches;
    int pattern, stitch;
    int N, M, K;
    int sum;
    
    while (true) {
        cin >> N >> M >> K;

        if (N == 0 && M == 0 && K == 0) {
            break;
        }

        stitches.clear();
        patterns.clear();
        stitches.push_back(N);

        for (int i = 0; i < K; i++) {
            cin >> pattern;
            patterns.push_back(pattern);
        }

        for (int i = 0; i < M-1; i++) {
            stitch = stitches[i] + patterns[i % K];
            stitches.push_back(stitch);
        }

        sum = accumulate(stitches.begin(), stitches.end(), 0);

        cout << sum << "\n";
    }
    return 0;
}

