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

	map<int, int> candy_km = {
		{1,1},
		{2,3},
		{3,5}
	};

	int TC;
	int G, C, E;
	int require;

	cin >> TC;

	while (TC--) {
		cin >> G >> C >> E;
		if (C >= E) {
			cout << 0 << "\n";
			continue;
		}
		require = (E - C) * candy_km[G];
		cout << require << "\n";

	}
	
}