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
	vector<int> X, Y;
	int x, y;
	int x4, y4;
	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}
	for (int i = 0; i < 3; i++) {
		if (count(X.begin(), X.end(), X[i]) == 1) {
			x4 = X[i];
		}
		if (count(Y.begin(), Y.end(), Y[i]) == 1) {
			y4 = Y[i];
		}
	}
	cout << x4 << " " << y4 << "\n";
	return 0;
}