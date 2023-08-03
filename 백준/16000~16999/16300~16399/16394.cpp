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
	int openYear = 1946;
	int currentYear;
	int anniversary;
	cin >> currentYear;
	anniversary = currentYear - openYear;
	cout << anniversary;
	return 0;
}