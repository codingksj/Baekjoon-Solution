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

	int N, num;
	cin >> N;
	while (true) {
		cin >> num;
		if (num == 0) {
			break;
		}
		if (num % N == 0) {
			cout << num << " is a multiple of " << N << "." << "\n";
		}
		else {
			cout << num << " is NOT a multiple of " << N << "." << "\n";
		}
	}
	return 0;
}