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

	const int DISCOUNT = 1500;
	const int NORMAL = 3000;

	int use, left;
	int canUse;
	cin >> use >> left;
	canUse = left + 60;
	if (canUse >= use) {
		cout << use * DISCOUNT;
	}
	else {
		cout << canUse * DISCOUNT + (use - canUse) * NORMAL;
	}
	return 0;
}