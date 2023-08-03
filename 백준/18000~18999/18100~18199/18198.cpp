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

	map<char, int> teams = {
		{'A',0},
		{'B',0}
	};
	char record[202], team;
	int L, score;

	cin >> record;

	L = strlen(record);

	for (int i = 0; i < L; i += 2) {
		team = record[i];
		score = record[i + 1] - '0';
		teams[team] += score;
	}

	(teams['A'] > teams['B']) ? cout << 'A' : cout << 'B';

	return 0;
}