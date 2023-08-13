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

	int people[51] = { 0, };
	int N, M, L;
	int count = 0;
	int curPos = 1;

	cin >> N >> M >> L;

	people[1] = 1;

	while (true) {
		if (people[curPos] == M) {
			break;
		}
		curPos = (people[curPos] & 1) ? ((curPos + L) % N) : (curPos - L);
		if (curPos <= 0) {
			curPos += N;
		}
		people[curPos]++;
		count++;
	}

	cout << count;

	return 0;
}

