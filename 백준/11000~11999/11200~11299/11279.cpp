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
	priority_queue<LL> PQ;
	bool isEmpty = false;
	int TC, command;
	cin >> TC;
	while (TC--) {
		cin >> command;
		isEmpty = PQ.empty();
		if (command != 0) {
			PQ.push(command);
			continue;
		}
		if (!isEmpty) {
			cout << PQ.top() << "\n";
			PQ.pop();
			continue;
		}
		cout << 0 << "\n";
	}
	return 0;
}