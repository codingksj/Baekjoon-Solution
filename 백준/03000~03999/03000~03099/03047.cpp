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
	
	vector<int> V;
	int n, pos;
	string ABC;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		V.push_back(n);
	}
	sort(V.begin(), V.end());
	cin >> ABC;
	for (auto letter : ABC) {
		pos = letter - 'A';
		cout << V[pos] << " ";
	}
	return 0;
}