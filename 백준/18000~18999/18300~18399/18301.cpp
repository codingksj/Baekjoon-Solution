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
	int n1, n2, n12, N;
	cin >> n1 >> n2 >> n12;
	N = floor(double(n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
	cout << N;
	return 0;
}