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
typedef pair<LL, LL> Pll;

typedef enum commands {
	PUSH = 1,
	POP,
	SIZE,
	EMPTY,
	TOP
}Commands;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC, cmd;
	stack<LL> stk;
	LL X;

	cin >> TC;

    while (TC--) {
        int cmd;
        cin >> cmd;

		if (cmd == PUSH) {
			cin >> X;
			stk.push(X);
		}
		else if (cmd == POP) {
			if (stk.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (cmd == SIZE) {
			cout << stk.size() << "\n";
		}
		else if (cmd == EMPTY) {
			cout << (stk.empty() ? 1 : 0) << "\n";
		}
		else if (cmd == TOP) {
			cout << (stk.empty() ? -1 : stk.top()) << "\n";
		}
    }
	return 0;
}
