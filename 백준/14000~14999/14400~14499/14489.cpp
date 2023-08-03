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
	LL account1, account2;
	LL chicken;
	LL sum, balance;
	cin >> account1 >> account2;
	cin >> chicken;
	sum = account1 + account2;
	balance = sum - 2LL * chicken;
	balance < 0 ? cout << sum : cout << balance;
	return 0;
}