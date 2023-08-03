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
	string name, clothes;
	map<string, int> fashion;
	int TC, N;
	int ans;

	cin >> TC;
	while (TC--) {
		fashion.clear();
		cin >> N;
		while (N--) {
			cin >> name >> clothes;
			bool isExist = fashion.find(clothes) != fashion.end();
			isExist ? fashion[clothes]++ : fashion[clothes] = 1;
		}
		ans = 1;
		for (auto it : fashion) {
			ans *= (it.second + 1);
		}
		ans -= 1;
		cout << ans << "\n";
	}
	return 0;
}