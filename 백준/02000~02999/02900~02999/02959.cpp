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
	
	int side[4];
	int i, j, key;
	for (int i = 0; i < 4; i++) {
		cin >> side[i];
	}
	for (i = 1; i < 4; i++) {
		key = side[i];
		for (j = i - 1; j >= 0 && side[j] > key; j--) {
			side[j + 1] = side[j];
		}
		side[j + 1] = key;
	}
	cout << side[0] * side[2];
	return 0;
}