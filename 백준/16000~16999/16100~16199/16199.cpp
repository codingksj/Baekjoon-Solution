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

typedef struct _date {
	int year;
	int month;
	int day;
}Date;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool cond1, cond2;
	Date D1, D2;
	int y1, y2, y3;
	int dy;
	cin >> D1.year >> D1.month >> D1.day;
	cin >> D2.year >> D2.month >> D2.day;

	cond1 = D1.month < D2.month;
	cond2 = D1.month == D2.month && D1.day <= D2.day;
	dy = D2.year - D1.year;

	y1 = (cond1 || cond2) ? dy : dy - 1;
	y2 = dy + 1;
	y3 = dy;
	cout << y1 << "\n" << y2 << "\n" << y3 << "\n";
	return 0;
}