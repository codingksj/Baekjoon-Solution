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
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int count9;
	int num;
	int total9 = 0;
	int row_max, col_max, max9;
	vector<int> row, col;

	cin >> N >> M;

	row.resize(N + 1);
	col.resize(M + 1);

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			count9 = 0;

			cin >> num;

			while (num) {
				(num % 10 == 9) && count9++;
				num /= 10;
			}

			row[r] += count9;
			col[c] += count9;
			total9 += count9;
		}
	}

	row_max = *max_element(row.begin(), row.end());
	col_max = *max_element(col.begin(), col.end());
	max9 = max(row_max, col_max);

	cout << total9 - max9;

	return 0;
}

