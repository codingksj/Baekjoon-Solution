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

	int N, M;
	string kind;
	cin >> N >> M;
	if (M == 1 || M == 2) {
		kind = "NEWBIE!";
	}
	else if (M <= N) {
		kind = "OLDBIE!";
	}
	else {
		kind = "TLE!";
	}
	cout << kind;
	return 0;
}