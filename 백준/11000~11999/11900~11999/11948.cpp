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
	vector<int> Va, Vb;
	int subject;
	int sum;
	int score = 0;
	for (int i = 0; i < 4; i++) {
		cin >> subject;
		Va.push_back(subject);
	}
	for (int i = 0; i < 2; i++) {
		cin >> subject;
		Vb.push_back(subject);
	}
	sum = accumulate(Va.begin(), Va.end(), 0) 
		- *min_element(Va.begin(), Va.end()) 
		+ *max_element(Vb.begin(), Vb.end());

	cout << sum;
	return 0;
}