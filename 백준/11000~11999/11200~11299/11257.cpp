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
	bool scoreF, minF;
	int TC;
	int S, M, T;
	int score;
	string ID;
	string result;
	cin >> TC;
	while (TC--) {
		result = "PASS";
		cin >> ID >> S >> M >> T;
		score = S + M + T;
		scoreF = score < 55;
		minF = (100 * S) < 30 * 35 || (100 * M) < 30 * 25 || (100 * T) < 30 * 40;
		if (scoreF || minF) {
			result = "FAIL";
		}
		cout << ID << " " << score << " " << result << "\n";
	}
	return 0;
}