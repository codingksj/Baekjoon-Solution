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

typedef struct _book {
	int price;
	int num;
}Book;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, cost1, cost2;
	Book X, Y;

	cin >> N >> X.num >> X.price >> Y.num >> Y.price;

	cost1 = ceil((double)N / X.num) * X.price;
	cost2 = ceil((double)N / Y.num) * Y.price;

	cout << min(cost1, cost2);

	return 0;
}