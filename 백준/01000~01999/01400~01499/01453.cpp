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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, computer;
	int refusal = 0;
	bool computers[101];

	fill(computers, computers + 101, true);

	cin >> N;

	while (N--) {
		cin >> computer;
		if (computers[computer]) {
			computers[computer] = false;
			continue;
		}
		refusal++;
	}

	cout << refusal;
	return 0;
}

