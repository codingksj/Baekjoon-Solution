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
typedef unsigned long long ULL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int sum_of_dice[81] = {0,};
	int S1, S2, S3;
	int sum;
	int maxV = -1, ans = -1;
	
	cin >> S1 >> S2 >> S3;

	for (int d1 = 1; d1 <= S1; d1++) {
		for (int d2 = 1; d2 <= S2; d2++) {
			for (int d3 = 1; d3 <= S3; d3++) {
				sum = d1 + d2 + d3;
				sum_of_dice[sum]++;
			}
		}
	}

	for (int i = 3; i <= 80; i++) {
		if (sum_of_dice[i] > maxV) {
			maxV = sum_of_dice[i];
			ans = i;
		}
	}

	cout << ans;

	return 0;
}
