#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	bool lunch, alcohol, cond;
	int T, S;
	cin >> T >> S;
	lunch = !(T < 12 || T > 16);
	alcohol = S > 0;
	cond = !lunch || alcohol;

	cond ? cout << 280 : cout << 320;
	return 0;
}