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

	deque<int> people;
	deque<string> yosephus;
	int N, K;

	cin >> N >> K;

	yosephus.push_back("<");

	for (int i = 1; i <= N; i++) {
		people.push_back(i);
	}

	while (!people.empty()) {
		for (int i = 1; i < K; i++) {
			people.push_back(people.front());
			people.pop_front();
		}
		yosephus.push_back(to_string(people.front()));
		people.pop_front();

		if (!people.empty()) {
			yosephus.push_back(", ");
		}
	}

	yosephus.push_back(">");

	for (auto e : yosephus) {
		cout << e;
	}
	return 0;
}
