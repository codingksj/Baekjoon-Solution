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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, bool> S;
	string word;
	int N, M;
	int count = 0;

	cin >> N >> M;

	while (N--) {
		cin >> word;
		S[word] = true;
	}

	while (M--) {
		cin >> word;
		if (S[word]) {
			count++;
		}
	}

	cout << count;

	return 0;
}

