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

LL GetHarmonic(double num) {
	double sum = 0.0;
	for (LL card = 1;;card++) {
		sum += 1.0 / (card + 1LL);
		if (sum < num) {
			continue;
		}
		return card;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double num;
	LL cards;
	
	while (true) {
		cin >> num;
		if (num == 0.00) {
			break;
		}
		cards = GetHarmonic(num);
		cout << cards << " card(s)" << "\n";
	}
	return 0;
}