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
	int x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) {
			break;
		}
		if (x > y) {
			swap(x, y);
		}
		if (y > z) {
			swap(y, z);
		}
		(x * x + y * y == z * z) ? cout << "right\n" : cout << "wrong\n";
	}
	return 0;
}