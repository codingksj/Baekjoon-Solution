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
	
	int TC, n, sum;
	vector<int> even;
	cin >> TC;
	while (TC--) {
		sum = 0;
		even.clear();
		for (int i = 0; i < 7; i++) {
			cin >> n;
			if (!(n & 1)) {
				even.push_back(n);
				sum += n;
			}
		}
		cout << sum << " " << *min_element(even.begin(), even.end()) << "\n";
	}
	return 0;
}