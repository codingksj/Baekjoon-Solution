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

string FindWinner(int score1, int score2) {
	if (score1 > score2) {
		return "Player 1";
	}
	else if (score1 < score2) {
		return "Player 2";
	}
	else {
		return "TIE";
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool win1, win2;
	int TC, game, score1, score2;
	char p1, p2;

	cin >> TC;
	while (TC--) {
		cin >> game;
		score1 = score2 = 0;
		while (game--) {
			cin >> p1 >> p2;
			win1 = p1 == 'R' && p2 == 'S' || p1 == 'S' && p2 == 'P' || p1 == 'P' && p2 == 'R';
			win2 = p2 == 'R' && p1 == 'S' || p2 == 'S' && p1 == 'P' || p2 == 'P' && p1 == 'R';
			win1&& score1++;
			win2&& score2++;
		}
		cout << FindWinner(score1, score2) << "\n";
	}
	return 0;
}