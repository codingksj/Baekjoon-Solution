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
	int TC, w, h;
	cin >> TC;
	while (TC--) {
		cin >> w >> h;
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				cout << "X";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}