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

	cin >> TC;

	for (int x = 1; x <= TC; x++) {
		cin >> A >> B;
		cout << "Case #" << x << ": " 
			<< A << " + " << B << " = " << A+B << "\n";
	}
	return 0;
}

