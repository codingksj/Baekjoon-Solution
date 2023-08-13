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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

#define MAX 1002

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int P[MAX];
	int N, time = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);
	for (int i = 0; i < N; i++) {
		time += P[i] * (N-i);
	}
	cout << time << "\n";
	return 0;
}
