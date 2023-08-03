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

	LL A, B, C;
	double M1, M2;
	LL answer;
	cin >> A >> B >> C;
	M1 = (A * B) / (double)C;
	M2 = ((double)A / B) * C;
	answer = M1 > M2 ? M1 : M2;
	cout << answer;
	return 0;
}