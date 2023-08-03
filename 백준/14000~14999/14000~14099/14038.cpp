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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int win = 0;
	char result;
	for (int i = 0; i < 6; i++) {
		cin >> result;
		(result == 'W') && win++;
	}
	win == 0 ? cout << -1 : cout << (8 - win) / 2;
	return 0;
}