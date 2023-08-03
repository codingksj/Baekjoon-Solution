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
	
	int TC, cost, area;
	int total_area = 0;
	int bedroom = 0;
	double total_price = 0;
	string room;

	cin >> TC >> cost;
	while (TC--) {
		cin >> area >> room;
		total_area += area;
		total_price += ((room == "balcony") ? 0.5 * cost * area : cost * area);
		(room == "bedroom") && (bedroom += area);
	}
	cout << total_area << "\n" << bedroom << "\n";
	cout << fixed;
	cout.precision(6);
	cout << total_price;
	return 0;
}