#include<iostream>
#include<sstream>
#include<bitset>
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
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c, d, e, f;
	int x, y;

	cin >> a >> b >> c >> d >> e >> f;

	x = (c * e - b * f) / (a * e - b * d);
	y = (a * f - c * d) / (a * e - b * d);

	cout << x << " " << y << "\n";

    return 0;
}
