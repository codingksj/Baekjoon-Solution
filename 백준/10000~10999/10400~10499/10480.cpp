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
	cin >> TC;
	while (TC--) {
		cin >> N;
		cout << N << " " << "is" << " ";
		N % 2 == 0 ? cout << "even" : cout << "odd";
		cout << "\n";
	}
	return 0;
}