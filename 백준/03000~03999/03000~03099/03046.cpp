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
	int R1, R2, S;
	cin >> R1 >> S;
	R2 = 2 * S - R1;
	cout << R2;
	return 0;
}