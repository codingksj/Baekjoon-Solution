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

LL GetFactBaseN(string N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL factN;
	string N;
	while (true) {
		cin >> N;
		if (N == "0") {
			break;
		}
		factN = GetFactBaseN(N);
		cout << factN << "\n";
	}
	return 0;
}

LL GetFactBaseN(string N) {
	LL num = 0, index = 0;
	LL w[] = { 1,2,6,24,120,720 };
	reverse(N.begin(), N.end());
	for (char i : N) {
		num += w[index] * (i - '0');
		index++;
	}
	return num;
};