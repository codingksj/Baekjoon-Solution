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
	
	int total, score;
	int max_index, max_score = 0;
	for (int i = 1; i <= 5; i++) {
		total = 0;
		for (int j = 1; j <= 4; j++) {
			cin >> score;
			total += score;
		}
		if (total > max_score) {
			max_score = total;
			max_index = i;
		}
	}
	cout << max_index << " " << max_score;
	return 0;
}