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
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL Ur, Tr, Uo, To, ans;
	cin >> Ur >> Tr >> Uo >> To;
	ans = 56 * Ur + 24 * Tr + 14 * Uo + 6 * To;
	cout << ans;
	return 0;
}