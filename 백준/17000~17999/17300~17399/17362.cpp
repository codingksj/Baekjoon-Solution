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
	int N, R;
	map<int, int> table = {
		{0,2},
		{1,1},
		{2,2},
		{3,3},
		{4,4},
		{5,5},
		{6,4},
		{7,3},
	};
	cin >> N;
	R = N % 8;
	cout << table[R];
	return 0;
}