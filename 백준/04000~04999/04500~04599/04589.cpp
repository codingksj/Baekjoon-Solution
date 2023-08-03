#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC;
	int a, b, c;
	bool asc, des;
	cin >> TC;
	cout << "Gnomes:" << "\n";
	while (TC--) {
		cin >> a >> b >> c;
		asc = a < b && b < c;
		des = a > b && b > c;
		if (asc || des) {
			cout << "Ordered" << "\n";
		}
		else {
			cout << "Unordered" << "\n";
		}
	}
	return 0;
}