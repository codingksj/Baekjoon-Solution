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

	int a, b, x, y, T;
	int opt1, opt2;

	cin >> a >> x >> b >> y >> T;

	opt1 = T > 30 ? (a + (T - 30) * x * 21) : a;
	opt2 = T > 45 ? (b + (T - 45) * y * 21) : b;

	cout << opt1 << " " << opt2 << "\n";

	return 0;
}