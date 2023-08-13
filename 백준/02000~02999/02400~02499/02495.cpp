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

int FindLongestStreak(string number);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string number;

	for (int i = 0; i < 3; i++) {
		getline(cin, number);
		cout << FindLongestStreak(number) << "\n";
	}

	return 0;
}

int FindLongestStreak(string number) {
	int curL = 0;
	int maxL = 0;
	char before = number[0];
	for (char now : number) {
		(now == before) ? curL++ : curL = 1;
		before = now;
		(curL > maxL) && (maxL = curL);
	}
	return maxL;
};
