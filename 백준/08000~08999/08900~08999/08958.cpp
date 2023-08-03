#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, count, score;
	string quiz;
	cin >> TC;
	while (TC--) {
		count = score = 0;
		cin >> quiz;
		for (auto it : quiz) {
			if (it == 'X') {
				count = 0;
				continue;
			}
			count++;
			score += count;
		}
		cout << score << "\n";
	}
	return 0;
}