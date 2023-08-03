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

	int A1, A2, A3;
	int t1, t2, t3;
	int time;

	cin >> A1 >> A2 >> A3;

	t1 = A2 * 2 + A3 * 4;
	t2 = A1 * 2 + A3 * 2;
	t3 = A1 * 4 + A2 * 2;
	
	time = min(t1, min(t2, t3));
	cout << time << "\n";
	
	return 0;
}