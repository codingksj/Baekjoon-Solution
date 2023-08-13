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
typedef pair<LL, LL> Pll;

typedef struct _date {
	int year;
	int month;
	int day;
	bool isLeapYear;
}Date;

int GetTotalDay(Date& D);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Date D;
	bool cond1, cond2;

	while (true) {
		cin >> D.day >> D.month >> D.year;

		if (D.day == 0 && D.month == 0 && D.year == 0) {
			break;
		}

		cond1 = D.year % 4 == 0 && D.year % 100 != 0;
		cond2 = D.year % 400 == 0;

		D.isLeapYear = (cond1 || cond2);
		cout << GetTotalDay(D) << "\n";
	}

	return 0;
}

int GetTotalDay(Date& D) {
	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 각 월의 일 수

	int totalDays = 0;

	if (D.isLeapYear) {
		daysInMonth[2] = 29;
	}

	for (int i = 1; i < D.month; ++i) {
		totalDays += daysInMonth[i];
	}

	totalDays += D.day;

	return totalDays;
}
