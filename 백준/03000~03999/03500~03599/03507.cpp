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
	
	int ATE, d1, d2;
	int lucky = 0;
	cin >> ATE;
	if (!(ATE > 198)) {
		for (d1 = 0; d1 <= 99; d1++) {
			for (d2 = 0; d2 <= 99; d2++) {
				if (ATE == d1 + d2) {
					lucky++;
				}
			}
		}
	}
	cout << lucky;
	return 0;
}