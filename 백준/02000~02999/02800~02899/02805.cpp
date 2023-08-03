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

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

#define MAX 1000002
LL trees[MAX];


LL GetSum(int N) {
	LL sum = 0;
	for (int i = 0; i < N; i++) {
		sum += trees[i];
	}
	return sum;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL N, M;
	LL start = 0, mid, end = 0;
	LL sum, max_height;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (trees[i] > end) {
			end = trees[i];
		}
	}
	max_height = 0;
	while (start <= end) {
		sum = 0;
		mid = (start + end) / 2;
		for (LL i = 0; i < N; i++) {
			if (trees[i] > mid) {
				sum += trees[i] - mid;
			}
		}
		if (sum < M) {
			end = mid - 1;
		}
		else {
			max_height = mid;
			start = mid + 1;
		}
	}
	cout << max_height;
	return 0;
}