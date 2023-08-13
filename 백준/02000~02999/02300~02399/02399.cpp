#include<iostream>
#include<bitset>
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

LL CalcSumOfDistance(vector<LL>& V);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<LL> X;
	LL x, answer;
	int TC;

	cin >> TC;

	while (TC--) {
		cin >> x;
		X.push_back(x);
	}

	answer = CalcSumOfDistance(X);

	cout << answer;

	return 0;
}

LL CalcSumOfDistance(vector<LL>& V) {
	LL answer = 0;
	LL distance;
	int maxL = V.size();

	for (int i = 0; i < maxL; i++) {
		for (int j = 0; j < maxL; j++) {
			if (i == j) {
				continue;
			}
			distance = abs(V[i] - V[j]);
			answer += distance;
		}
	}
	return answer;
};
