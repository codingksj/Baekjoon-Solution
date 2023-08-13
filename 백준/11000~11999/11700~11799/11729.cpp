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

void Hanoi(int step, int src, int via, int dest) {
	if (step == 1) {
		cout << src << " " << dest << "\n";
	}
	else {
		Hanoi(step - 1, src, dest, via);
		cout << src << " " << dest << "\n";
		Hanoi(step - 1, via, src, dest);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer;

	cin >> N;

	answer = (1 << N) - 1;

	cout << answer << "\n";

	Hanoi(N, 1, 2, 3);

	return 0;
}
