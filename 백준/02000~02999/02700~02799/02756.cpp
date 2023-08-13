#include<iostream>
#include<sstream>
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
typedef pair<LL, LL> PLL;

typedef struct _dart {
	double x;
	double y;
}Dart;

int GetScore(Dart& d);
string ChooseWhoIsWinner(int score1, int score2);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Dart p1, p2;
	double x, y;
	int TC;
	int score1, score2;

	cin >> TC;
	
	while (TC--) {
		score1 = score2 = 0;
		for (int i = 0; i < 3; i++) {
			cin >> x >> y;
			p1 = { abs(x), abs(y) };
			score1 += GetScore(p1);
		}
		for (int i = 0; i < 3; i++) {
			cin >> x >> y;
			p2 = { abs(x), abs(y) };
			score2 += GetScore(p2);
		}
		cout << ChooseWhoIsWinner(score1, score2) << "\n";
	}

	return 0;
}

int GetScore(Dart& d) {
	map<int, int> table = {
		{0,100},
		{1,100},
		{2,80},
		{3,60},
		{4,40},
		{5,20}
	};
	int score;
	int distance = ceil(sqrt(pow(d.x, 2) + pow(d.y, 2))/3);

	score = table[distance];

	return score;
};

string ChooseWhoIsWinner(int score1, int score2) {
	string answer = "SCORE: ";
	string winner;
	answer += (to_string(score1) + " to " + to_string(score2) + ", ");
	if (score1 > score2) {
		winner = "PLAYER 1 WINS.";
	}
	else if (score1 < score2) {
		winner = "PLAYER 2 WINS.";
	}
	else {
		winner = "TIE.";
	}
	answer += winner;

	return answer;
};
