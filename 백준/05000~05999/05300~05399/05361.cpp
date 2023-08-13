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
typedef pair<LL, LL> Pll;

void CalculateTotalPrice(double price[], int amount[], double& total);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	int amount[5];
	double total;
	double price[5] = {
		350.34, 
		230.90, 
		190.55,
		125.30, 
		180.90
	};
	cin >> TC;

	while (TC--) {
		for (int i = 0; i < 5; i++) {
			cin >> amount[i];
		}
		CalculateTotalPrice(price, amount, total);
		cout << fixed;
		cout.precision(2);
		cout << "$" << total << "\n";
	}
	return 0;
}

void CalculateTotalPrice(double price[], int amount[], double& total) {
	total = 0;
	for (int i = 0; i < 5; i++) {
		total += (price[i] * amount[i]);
	}
};