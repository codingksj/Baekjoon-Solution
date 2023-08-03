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
	set<LL> tmp;
	vector<LL> A;
	LL input, sum, X, count = 0;
	int N;
	int left, right;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		tmp.insert(input);
	}
	cin >> X;
	A = vector<LL>(tmp.begin(), tmp.end());
	left = 0; right = N - 1;
	while (left < right) {
		sum = A[left] + A[right];
		if (sum > X) {
			right--;
		}
		else if (sum < X) {
			left++;
		}
		else {
			count++;
			left++;
			right--;
		}
	}
	cout << count;
	return 0;
}