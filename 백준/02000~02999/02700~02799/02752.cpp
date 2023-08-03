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
	set<int> num;
	int input;
	for (int i = 0; i < 3; i++) {
		cin >> input;
		num.insert(input);
	}
	for (auto it : num) {
		cout << it << " ";
	}
	return 0;
}