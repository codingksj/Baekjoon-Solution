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
	int score;
	map<int, char> table;
	table[10] = table[9] = 'A';
	table[8] = 'B';
	table[7] = 'C';
	table[6] = 'D';
	table[5] = table[4] = table[3] = table[2] = table[1] = table[0] = 'F';

	cin >> score;
	cout << table[score / 10];
	return 0;
}