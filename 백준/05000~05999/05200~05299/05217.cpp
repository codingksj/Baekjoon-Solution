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
typedef pair<LL, LL> Pll;

void GetPairs(LL N, vector<Pll>& V) {
	LL left = 1LL, right = N-1LL;
	Pll P;
	while (left < right) {
		P = { left,right };
		V.push_back(P);
		left++;
		right--;
	}
}

void PrintPairs(vector<Pll>& V) {
	LL maxN = V.size();
	if (maxN == 1) {
		cout << V[0].first << " " << V[0].second;
	}
	else if (maxN > 1) {
		for (LL i = 0; i < maxN; i++) {
			cout << V[i].first << " " << V[i].second;
			if (i < maxN - 1) {
				cout << ", ";
			}
		}
	}
	cout << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<Pll> pairs;
	LL TC, N;
	cin >> TC;
	while (TC--) {
		pairs.clear();
		cin >> N;
		cout << "Pairs for " << N << ": ";
		GetPairs(N, pairs);
		PrintPairs(pairs);
	}
	return 0;
}