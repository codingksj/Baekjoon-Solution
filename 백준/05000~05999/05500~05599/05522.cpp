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
	int N, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> N;
		sum += N;
	}
	cout << sum << "\n";
	return 0;
}