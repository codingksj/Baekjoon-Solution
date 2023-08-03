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
	
	int maxTeam;
	int N, M, K;
	cin >> N >> M >> K;

	maxTeam = min(min(M, N / 2), (N + M - K) / 3);
	cout << maxTeam;

	return 0;
}