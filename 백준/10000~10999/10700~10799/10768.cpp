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
	int month, day;
	cin >> month >> day;
	if (month < 2) {
		cout << "Before";
	}
	else if (month > 2) {
		cout << "After";
	}
	else {
		if (day < 18) {
			cout << "Before";
		}
		else if (day > 18) {
			cout << "After";
		}
		else {
			cout << "Special";
		}
	}
	return 0;
}