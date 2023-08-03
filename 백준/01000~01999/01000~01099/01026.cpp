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
	vector<LL> A, B;
	LL N, input, S = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		B.push_back(input);
	}
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	for (int i = 0; i < N; i++) {
		S += (A[i] * B[i]);
	}
	cout << S;
	return 0;
}