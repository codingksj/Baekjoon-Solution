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
typedef struct _basket {
	int apple;
	int orange;
}Basket;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Basket b1, b2;
	int apple, orange;
	cin >> b1.apple >> b1.orange;
	cin >> b2.apple >> b2.orange;

	apple = b1.apple + b2.orange;
	orange = b1.orange + b2.apple;

	cout << min(apple, orange);
	return 0;
}