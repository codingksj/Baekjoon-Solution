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

	int cards[21];

	for (int i = 1; i <= 20; i++) {
		cards[i] = i;
	}

	int TC = 10;
	int delta;
	int left, mid, right;

	while (TC--) {
		cin >> left >> right;
		mid = (left + right)/2;
		delta = right - left;
		if (delta == 0) {
			continue;
		}
		else if (delta == 1) {
			swap(cards[left], cards[right]);
		}
		else {
			for (int i = 0; i <= delta/2; i++) {
				swap(cards[left + i], cards[right - i]);
			}
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout << cards[i] << " ";
	}
	return 0;
}