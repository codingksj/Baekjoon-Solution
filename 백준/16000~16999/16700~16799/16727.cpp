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

	int p1, s1, p2, s2;
	cin >> p1 >> s1 >> s2 >> p2;
	if (p1 + p2 > s1 + s2) {
		cout << "Persepolis";
	}
	else if (p1 + p2 < s1 + s2) {
		cout << "Esteghlal";
	}
	else {
		if (s1 < p2) {
			cout << "Persepolis";;
		}
		else if (s1 > p2) {
			cout << "Esteghlal";
		}
		else {
			cout << "Penalty";
		}
	}
	return 0;
}