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
typedef pair<LL, LL> PLL;

void ChooseWhoIsWinner(vector<int>& cardA, vector<int>& cardB);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> cardA, cardB;
	int card;

	for (int i = 0; i < 10; i++) {
		cin >> card;
		cardA.push_back(card);
	}
	for (int i = 0; i < 10; i++) {
		cin >> card;
		cardB.push_back(card);
	}

	ChooseWhoIsWinner(cardA, cardB);

	return 0;
}

void ChooseWhoIsWinner(vector<int>& cardA, vector<int>& cardB) {
	stack<char> result;

	int maxL = cardA.size();
	int scoreA = 0, scoreB = 0;
	char winner;

	for (int i = 0; i < maxL; i++) {
		if (cardA[i] == cardB[i]) {
			scoreA += 1;
			scoreB += 1;
			result.push('D');
			continue;
		}
		if (cardA[i] > cardB[i]) {
			scoreA += 3;
			result.push('A');
		}
		else {
			scoreB += 3;
			result.push('B');
		}
	}

	if (scoreA > scoreB) {
		winner = 'A';
	}
	else if (scoreA < scoreB) {
		winner = 'B';
	}
	else {
		while (!result.empty() && result.top() == 'D') {
			result.pop();
		}
		winner = result.empty() ? 'D' : result.top();
	}
	cout << scoreA << " " << scoreB << "\n";
	cout << winner;


};
