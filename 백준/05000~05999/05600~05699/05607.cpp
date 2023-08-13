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
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	int A, B;
	int scoreA = 0, scoreB = 0;

	cin >> TC;
	while (TC--) {
		cin >> A >> B;
		if (A > B) {
			scoreA += (A + B);
		}
		else if (A < B) {
			scoreB += (A + B);
		}
		else {
			scoreA += A;
			scoreB += B;
		}
	}
	cout << scoreA << " " << scoreB << "\n";
}
