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
	
	int TC;
	double X, Y, price, minV;
	vector<double> tri_gimbap;

	cin >> X >> Y;
	price = 1000.0 * X / Y;
	tri_gimbap.push_back(price);
	cin >> TC;

	while (TC--) {
		cin >> X >> Y;
		price = 1000.0 * X / Y;
		tri_gimbap.push_back(price);
	}
	minV = *min_element(tri_gimbap.begin(), tri_gimbap.end());
	cout << fixed;
	cout.precision(2);
	cout << minV;

	return 0;
}