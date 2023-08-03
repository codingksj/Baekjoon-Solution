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

	vector<pair<int, string>> univ;
	string warning;
	int sum;
	int low;
	int S, K, H;

	cin >> S >> K >> H;
	sum = S + K + H;

	univ.push_back({ S, "Soongsil" });
	univ.push_back({ K, "Korea" });
	univ.push_back({ H, "Hanyang" });
	low = min(S, min(K, H));
	for (auto it : univ) {
		if (it.first == low) {
			warning = it.second;
		}
	}
	sum < 100 ? cout << warning : cout << "OK";

	return 0;
}