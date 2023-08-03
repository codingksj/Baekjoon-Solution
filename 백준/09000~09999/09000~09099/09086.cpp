#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC;
	string S;
	cin >> TC;
	while (TC--) {
		cin >> S;
		cout << *S.begin() << *S.rbegin() << "\n";
	}
	return 0;
}