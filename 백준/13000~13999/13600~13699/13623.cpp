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
	int a, b, c;
	cin >> a >> b >> c;
	if (a != b && a != c) {
		cout << 'A';
	}
	else if (b != a && b != c) {
		cout << 'B';
	}
	else if (c != a && c != b) {
		cout << 'C';
	}
	else {
		cout << '*';
	}
	return 0;
}