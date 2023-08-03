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

	int balls[4] = { 0,1,2,3 };
	int X, Y, TC;
	cin >> TC;
	while (TC--) {
		cin >> X >> Y;
		swap(balls[X], balls[Y]);
	}
	for (int i = 1; i <= 3; i++) {
		if (balls[i] == 1) {
			cout << i;
			break;
		}
	}
	return 0;
}