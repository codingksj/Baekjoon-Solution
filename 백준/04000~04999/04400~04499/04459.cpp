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

	map<int, string> Rules;
	string rule;
	string N;
	int TC;
	int number;

	getline(cin, N);
	TC = stoi(N);
	for (int i = 1; i <= TC; i++) {
		getline(cin, rule);
		Rules[i] = rule;
	}
	cin >> TC;
	while (TC--) {
		cin >> number;
		if (Rules[number]!="") {
			rule = Rules[number];
		}
		else {
			rule = "No such rule";
		}
		cout << "Rule" << " " << number << ":" << " " << rule << "\n";
	}
	return 0;
}