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

	int TC;
	LL G, S;
	LL scoreS, scoreG;
	map<LL, LL> table_g = {
		{0,1LL},
		{1,2LL},
		{2,3LL},
		{3,3LL},
		{4,4LL},
		{5,10LL}
	};
	map<LL, LL> table_s = {
		{0,1LL},
		{1,2LL},
		{2,2LL},
		{3,2LL},
		{4,3LL},
		{5,5LL},
		{6,10LL}
	};
	string dialogue;

	cin >> TC;
	for (int battle = 1; battle <= TC; battle++) {
		scoreS = scoreG = 0;
		for (int i = 0; i < 6; i++) {
			cin >> G;
			scoreG += (G * table_g[i]);
		}
		for (int i = 0; i < 7; i++) {
			cin >> S;
			scoreS += (S * table_s[i]);
		}
		if (scoreG > scoreS) {
			dialogue = "Good triumphs over Evil";
		}
		else if (scoreG < scoreS) {
			dialogue = "Evil eradicates all trace of Good";
		}
		else {
			dialogue = "No victor on this battle field";
		}
		cout << "Battle" << " " << battle << ":" << " " << dialogue << "\n";
	}
	return 0;
}