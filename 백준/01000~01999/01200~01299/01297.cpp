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
typedef unsigned long long ULL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int D, H, W;
	int realH, realW;
	double k;

	cin >> D >> H >> W;

	k = D/sqrt(H * H + W * W);

	realH = int(floor(k * H));
	realW = int(floor(k * W));
	
	cout << realH << " " << realW;

	return 0;
}
