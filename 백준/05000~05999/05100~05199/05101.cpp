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

	LL a, a1, d, an;
	LL R, Q;
	bool IsSeq;
	while (true) {
		cin >> a1 >> d >> an;
		if (a1 == 0 && d == 0 && an == 0) {
			break;
		}
		a = a1 - d;
		R = (an - a) % d;
		Q = (an - a) / d;
		IsSeq = !R && (Q > 0);
		IsSeq ? cout << Q : cout << "X";
		cout << "\n";
	}
	return 0;
}