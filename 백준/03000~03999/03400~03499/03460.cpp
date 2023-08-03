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
	int n;
	int count;

	cin >> TC;
	while (TC--) {
		count = 0;
		cin >> n;
		for (int i = 1; i <= n; i <<= 1) {
			if ((n & i) == i) {
				cout << count << " ";
			}
			count++;
		}
		cout << "\n";
	}
	return 0;
}