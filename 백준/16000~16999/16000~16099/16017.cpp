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

	bool cond1, cond2, cond3;
	int digit[4];
	for (int i = 0; i < 4; i++) {
		cin >> digit[i];
	}
	cond1 = digit[0] == 8 || digit[0] == 9;
	cond2 = digit[3] == 8 || digit[3] == 9;
	cond3 = digit[1] == digit[2];
	(cond1 && cond2 && cond3) ? cout << "ignore" : cout << "answer";
	return 0;
}