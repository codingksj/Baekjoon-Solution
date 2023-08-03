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
	
	int balance, amount, left;
	char func;
	map<char, int> weight = {
		{'W',-1},
		{'D',1}
	};
	bool cond1, cond2, cond3;
	while (true) {
		cin >> balance >> func >> amount;
		cond1 = balance == 0;
		cond2 = func == 'W';
		cond3 = amount == 0;
		if (cond1 && cond2 && cond3) {
			break;
		}
		left = balance + weight[func] * amount;
		left < -200 ? cout << "Not allowed" << "\n" : cout << left << "\n";
	}
	return 0;
}