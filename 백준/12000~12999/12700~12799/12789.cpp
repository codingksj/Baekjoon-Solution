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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	deque<int> line;
	stack<int> wait;
	vector<int> students;

	int TC, N;
	int curN = 1;
	bool IsAsc;

	cin >> TC;

	while (TC--) {
		cin >> N;
		line.push_back(N);
	}

	while (!line.empty()) {
		if (line.front() == curN) {
			line.pop_front();
			students.push_back(curN);
			curN++;
		}
		else if (!wait.empty() && wait.top() == curN) {
			wait.pop();
			students.push_back(curN);
			curN++;
		}
		else {
			wait.push(line.front());
			line.pop_front();
		}
	}

	while (!wait.empty()) {
		students.push_back(wait.top());
		wait.pop();
	}

	IsAsc = is_sorted(students.begin(), students.end());

	cout << (IsAsc ? "Nice" : "Sad") << "\n";

	return 0;
}
