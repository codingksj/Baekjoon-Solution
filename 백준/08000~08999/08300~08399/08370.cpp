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
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n1, k1, n2, k2;
	cin >> n1 >> k1 >> n2 >> k2;
	cout << n1 * k1 + n2 * k2;
	return 0;
}