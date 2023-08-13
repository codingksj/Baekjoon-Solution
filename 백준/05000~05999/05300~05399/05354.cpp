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
typedef pair<LL, LL> Pll;

void PrintJBox(int size) {
	bool IsJRange;
	bool IsJRow, IsJCol;

	for (int r = 1; r <= size; r++) {
		for (int c = 1; c <= size; c++) {
			IsJRow = r > 1 && r < size;
			IsJCol = c > 1 && c < size;
			IsJRange = IsJRow && IsJCol;
			cout << (IsJRange ? "J" : "#");
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	int size;

	cin >> TC;

	while (TC--) {
		cin >> size;
		PrintJBox(size);
	}

	return 0;
}