#include<iostream>
#include<bitset>
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
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int CalculatePrize(vector<int>& dices);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> dices;
	int TC;
	int dice, prize;
	int maxPrize = -1;

	cin >> TC;

	while (TC--) {
		dices.clear();
		for (int i = 0; i < 4; i++) {
			cin >> dice;
			dices.push_back(dice);
		}
		prize = CalculatePrize(dices);
		if (maxPrize < prize) {
			maxPrize = prize;
		}
	}
	
	cout << maxPrize;

	return 0;
}

int CalculatePrize(vector<int>& dices) {
	int faces[7] = { 0, };
	int max_face = -1;
	int prize;
	int p1 = -1, p2 = -1;

	for (auto dice : dices) {
		faces[dice]++;
	}
	for (int i = 1; i <= 6; i++) {
		if (faces[i] > max_face) {
			max_face = faces[i];
		}
	}
	if (max_face == 4) {
		prize = 50000 + dices[0] * 5000;
	}

	else if (max_face == 3) {
		for (int i = 6; i >= 1; i--) {
			if (faces[i] == 3) {
				prize = 10000 + i * 1000;
				break;
			}
		}
	}

	else if (max_face == 2) {
		for (int i = 6; i >= 1; i--) {
			if (faces[i] == 2) {
				(p1 == -1) ? p1 = i : p2 = i;
			}
		}
		prize = (p1 * p2 > 0) ? 
			(2000 + (p1 + p2) * 500) : 
			(1000 + p1 * 100);
	}

	else {
		for (int i = 6; i >= 1; i--) {
			if (faces[i]) {
				prize = i * 100;
				break;
			}
		}
	}

	return prize;
};

