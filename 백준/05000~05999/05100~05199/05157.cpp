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

	map<LL, LL> Bonus;
	vector<LL> bailedCompany;
	LL TC, B, C, N, R, tax;
	LL company, bonus;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Bonus.clear();
		bailedCompany.clear();
		tax = 0;

		cin >> C >> B >> N >> R;
		while (B--) {
			cin >> company;
			bailedCompany.push_back(company);
		}
		while (N--) {
			cin >> company >> bonus;
			Bonus[company] += bonus * R / 100;
		}
		for (auto b : bailedCompany) {
			tax += Bonus[b];
		}
		cout << "Data Set " << i << ":" << "\n";
		cout << tax << "\n" << "\n";
	}
	return 0;
}