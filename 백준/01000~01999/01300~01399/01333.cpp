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

	LL N, L, D;
	LL fastest_time, total_time;
	LL music, call;

	cin >> N >> L >> D;

	total_time = N * L + (N - 1) * 5;

	music = L;
	call = D;
	fastest_time = ceil((double)total_time / D) * D;

	while (call <= total_time) {
		if (call < music) {
			call += D;
		}
		else if (call < music + 5) {
			fastest_time = call;
			break;
		}
		else {
			music += (L + 5);
		}
	}

	cout << fastest_time;

	return 0;
}
