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

#define PI 3.141592653589793

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double r, ans;
	LL area;

	cin >> area;

	r = sqrt((double)area / PI);
	ans = 2 * PI * r;

	cout.precision(12);
	cout << ans;

	return 0;
}