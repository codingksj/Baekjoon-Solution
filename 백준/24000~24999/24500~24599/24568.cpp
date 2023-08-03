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
typedef pair<int, int> Pii;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	const int R = 8, S = 3;
	int small, regular, total;
	cin >> regular >> small;
	total = R * regular + S * small;
	cout << total - 28;
	return 0;
}