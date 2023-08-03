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
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	deque<int> bowls;
	int bowl;
	for (int i = 0; i < 3; i++) {
		cin >> bowl;
		bowls.push_back(bowl);
	}
	sort(bowls.begin(), bowls.end());
	bowls.pop_back();
	bowls.pop_front();
	cout << bowls.front();
	return 0;
}