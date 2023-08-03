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
	int L, A, B, C, D;
	int maxL;
	cin >> L >> A >> B >> C >> D;
	maxL = L - max(ceil((double)A / C), ceil((double)B / D));
	cout << maxL;
	return 0;
}