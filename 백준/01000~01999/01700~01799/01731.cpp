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

	vector<LL> seq;
	LL element, d, r;
	LL answer;
	int N;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> element;
		seq.push_back(element);
	}

	answer = seq[N - 1];

	if (seq[0] + seq[2] == 2LL * seq[1]) {
		d = seq[1] - seq[0];
		answer += d;
	}

	else {
		r = seq[1] / seq[0];
		answer *= r;
	}

	cout << answer;

	return 0;
}

