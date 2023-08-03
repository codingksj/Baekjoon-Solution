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
	priority_queue<LL, vector<LL>, greater<LL>> heap;
	bool isEmpty;
	int TC, N;
	cin >> TC;
	while (TC--) {
		cin >> N;
		isEmpty = heap.empty();
		if (N == 0) {
			if (isEmpty) {
				cout << "0\n";
			}
			else {
				cout << heap.top() << "\n";
				heap.pop();
			}
		}
		else {
			heap.push(N);
		}
	}
	return 0;
}