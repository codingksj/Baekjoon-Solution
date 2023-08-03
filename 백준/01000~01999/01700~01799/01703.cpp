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

	vector<int> V;
	int leaves = 1;
	int age, branches, cut;
	while (true) {
		cin >> age;
		leaves = 1;
		if (age == 0) {
			break;
		}
		V.resize(2 * age);
		for (int i = 0; i < 2 * age; i++) {
			cin >> V[i];
		}
		for (int i = 0; i < age; i++) {
			branches = V[2 * i];
			cut = V[2 * i + 1];
			leaves = (leaves * branches - cut);
		}
		cout << leaves << "\n";
	}

	return 0;
}