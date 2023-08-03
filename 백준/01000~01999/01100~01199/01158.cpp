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
	deque<int> josephus;
	int N, K, count=0;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		josephus.push_back(i);
	}
	cout << "<";
	while (josephus.size()>1) {
		count++;
		if (count == K) {
			cout << josephus.front() << ", ";
			count = 0;
		}
		else {
			josephus.push_back(josephus.front());
		}
		josephus.pop_front();
	}
	cout << josephus.front() << ">";
	return 0;
}