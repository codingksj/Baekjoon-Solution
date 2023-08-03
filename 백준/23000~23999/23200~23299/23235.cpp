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
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	LL index = 1;
	while (true) {
		getline(cin, s);
		if (s == "0") {
			break;
		}
		cout << "Case " << index++ << ": Sorting... done!\n";
	}
	return 0;
}