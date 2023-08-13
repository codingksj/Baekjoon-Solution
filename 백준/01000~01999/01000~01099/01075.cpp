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

string MakeDivisible(LL N, LL F);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL N, F;

	cin >> N >> F;

	cout << MakeDivisible(N,F) << "\n";

	return 0;
}

string MakeDivisible(LL N, LL F) {
	LL start = (N / 100LL) * 100LL;
	LL i;
	string answer;
	for (i = 0; i < 100; i++) {
		if ((start + i) % F == 0) {
			break;
		}
	}
	if (i < 10) {
		answer = "0"+to_string(i);
	}
	else {
		answer = to_string(i);
	}
	return answer;
};


