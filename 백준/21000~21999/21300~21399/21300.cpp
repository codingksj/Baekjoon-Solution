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
	int beer, malt, wine, soft, seltze, water;
	int sum;
	cin >> beer >> malt >> wine >> soft >> seltze >> water;
	sum = beer + malt + wine + soft + seltze + water;
	cout << 5 * sum;
	return 0;
}