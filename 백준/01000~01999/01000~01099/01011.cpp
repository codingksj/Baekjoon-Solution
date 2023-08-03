#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC;
	long long x, y;
	long long distance, n, move;
	long long L1, L2;
	cin >> TC;
	while (TC--) {
		cin >> x >> y;
		distance = y - x;
		n = sqrt(distance);
		L1 = n * n;
		L2 = n * (n + 1);
		if (distance == L1) {
			move = 2 * n - 1;
		}
		else if (distance > L1 && distance <= L2) {
			move = 2 * n;
		}
		else {
			move = 2 * n + 1;
		}
		cout << move << "\n";
	}
	return 0;
}