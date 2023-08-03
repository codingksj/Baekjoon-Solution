#include<iostream>
#include<set>
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

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string S;
	char cmd, input;
	int TC;
	stack<char> Left, Right;
	
	cin >> S;
	for (auto it : S) {
		Left.push(it);
	}
	cin >> TC;
	while (TC--) {
		cin >> cmd;
		if (cmd == 'L' && !Left.empty()) {
			Right.push(Left.top());
			Left.pop();
		}
		else if (cmd == 'D' && !Right.empty()) {
			Left.push(Right.top());
			Right.pop();
		}
		else if (cmd == 'B' && !Left.empty()) {
			Left.pop();
		}
		else if (cmd == 'P') {
			cin >> input;
			Left.push(input);
		}
	}
	while (!Left.empty()) {
		Right.push(Left.top());
		Left.pop();
	}
	while (!Right.empty()) {
		cout << Right.top();
		Right.pop();
	}
	return 0;
}