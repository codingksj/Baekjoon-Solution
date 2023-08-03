#include<iostream>
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
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL N, w, d, sum;
    while (cin >> N >> w >> d >> sum) {
        LL total = w * N * (N - 1) / 2;
        LL ans = (total - sum) / d;
        cout << (ans == 0 ? N : ans) << "\n";
    }
	return 0;
}