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

	LL A, B, N;
	double nth_root;
	LL min, max, dm, dM;

	while (true) {
		cin >> B >> N;
		if (B == 0 && N == 0) {
			break;
		}
		nth_root = pow((double)B, 1.0 / N);
		min = ceil(nth_root);
		max = floor(nth_root);
		dm = abs(pow(min, N) - B);
		dM = abs(pow(max, N) - B);

		cout << (dm < dM ? min : max) << "\n";

	}
	return 0;
}