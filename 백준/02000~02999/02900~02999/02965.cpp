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
	
	int kangaroo[3];
	for (int i = 0; i < 3; i++) {
		cin >> kangaroo[i];
	}
	cout << max(kangaroo[2] - kangaroo[1], kangaroo[1] - kangaroo[0]) - 1;
	return 0;
}