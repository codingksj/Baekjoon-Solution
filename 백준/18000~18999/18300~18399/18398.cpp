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

	int TC, N;
	LL A, B;
	cin >> TC;
	while (TC--) {
		cin >> N;
		while (N--) {
			cin >> A >> B;
			cout << A + B << " " << A * B << "\n";
		}
	}
	return 0;
}