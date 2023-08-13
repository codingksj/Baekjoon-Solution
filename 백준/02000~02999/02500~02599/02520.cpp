#include<iostream>
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

	const double INGREDIENTS[] = { 0.5,0.5,0.25,0.0625,0.5625 };
	const int TOPPINGS[] = { 1,30,25,10 };

	int ingredient, topping;
	int TC;
	int usable_dough;
	int current_dough;
	int pancake;

	cin >> TC;

	while (TC--) {
		usable_dough = 1E+7 + 1;
		pancake = 0;

		for (int i = 0; i < 5; i++) {
			cin >> ingredient;
			current_dough = ingredient / INGREDIENTS[i];
			if (current_dough < usable_dough) {
				usable_dough = current_dough;
			}
		}
		for (int i = 0; i < 4; i++) {
			cin >> topping;
			pancake += topping / TOPPINGS[i];
		}
		cout << min(usable_dough, pancake) << "\n";
	}
	return 0;
}

