#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>

#define MAX 2187+1

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int paper[MAX][MAX];

int minus_one, zero, one;

bool CheckPaper(int x, int y, int size) {
	int sum = 0;
	int standard = paper[x][y];
	bool isPaper = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (paper[i][j] != standard) {
				isPaper = false;
				j = y + size;
				i = x + size;
				break;
			}
		}
	}
	return isPaper;
}
void GetPaperNum(int x, int y, int size) {
	bool same = CheckPaper(x, y, size);
	if (same) {
		if (paper[x][y] == -1) {
			minus_one++;
		}
		else if (paper[x][y] == 1) {
			one++;
		}
		else {
			zero++;
		}
	}
	else {
		GetPaperNum(x, y, size / 3); 
		GetPaperNum(x + size / 3, y, size / 3);
		GetPaperNum(x + size / 3 + size / 3, y, size / 3); 
		GetPaperNum(x, y + size / 3, size / 3); 
		GetPaperNum(x, y + size / 3 + size / 3, size / 3); 
		GetPaperNum(x + size / 3, y + size / 3, size / 3); 
		GetPaperNum(x + size / 3 + size / 3, y + size / 3 + size / 3, size / 3);
		GetPaperNum(x + size / 3, y + size / 3 + size / 3, size / 3); 
		GetPaperNum(x + size / 3 + size / 3, y + size / 3, size / 3); 
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> paper[i][j];
		}
	}
	GetPaperNum(0, 0, size);
	cout << minus_one << "\n"
		<< zero << "\n"
		<< one << "\n";

	return 0;
}