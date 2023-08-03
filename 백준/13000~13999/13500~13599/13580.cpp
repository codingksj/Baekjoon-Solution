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
	vector<int> time;
	int input;
	bool goHome;
	for (int i = 0; i < 3; i++) {
		cin >> input;
		time.push_back(input);
	}
	sort(time.begin(), time.end());
	goHome = (time[0] == time[1])
		|| (time[1] == time[2])
		|| (time[0] + time[1] == time[2]);
	goHome ? cout << "S" : cout << "N";
	return 0;
}