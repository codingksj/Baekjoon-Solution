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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

string CalcWeight(int w, int o);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int weight, weightOK;
	string interaction, val;
	bool death;

	for (int i = 1;; i++) {
		cin >> weightOK >> weight;
		if (weightOK == 0 && weight == 0) {
			break;
		}
		death = false;
		while (true) {
			cin >> interaction >> val;
			if (interaction == "#" && val == "0") {
				break;
			}
			(interaction == "F") && (weight += stoi(val));
			(interaction == "E") && (weight -= stoi(val));
			if (weight <= 0) {
				death = true;
			}
		}
		cout << i << " "
			<< (death ? "RIP" : CalcWeight(weight, weightOK))
			<< "\n";
	}

	return 0;
}

string CalcWeight(int w, int o) {
	bool healthy = (2 * w > o) && (w < 2 * o);
	return (healthy ? ":-)" : ":-(");
};
