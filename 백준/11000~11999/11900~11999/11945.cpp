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
	int N, M;
	char bread[11][11];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> bread[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			cout << bread[i][j];
		}
		cout << "\n";
	}
	return 0;
}