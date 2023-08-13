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

	char chess_board[8][8];
	bool pos_cond, piece_cond;
	int count = 0;

	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			cin >> chess_board[r][c];

			pos_cond = !((r + c) & 1);
			piece_cond = chess_board[r][c] == 'F';

			if (pos_cond && piece_cond) {
				count++;
			}
		}
	}
	cout << count;

	return 0;
}
