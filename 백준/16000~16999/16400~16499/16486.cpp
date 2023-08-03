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

#define PI 3.141592

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int d1, d2;
	double ans;
	cin >> d1 >> d2;
	ans = 2.0 * d1 + 2.0 * d2 * PI;
	cout.precision(10);
	cout << ans;
	return 0;
}