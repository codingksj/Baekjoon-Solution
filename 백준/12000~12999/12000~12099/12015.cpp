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
	vector<int> A, LIS;
	int N;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (LIS.empty() || LIS.back() < A[i]) {
			LIS.push_back(A[i]);
		}
		else {
			*lower_bound(LIS.begin(), LIS.end(), A[i]) = A[i];
		}
	}
	cout << LIS.size();
	return 0;
}