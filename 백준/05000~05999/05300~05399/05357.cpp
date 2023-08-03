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
	int TC;
	string data;
	string answer;
	char alpha;
	cin >> TC;
	while (TC--) {
		answer.clear();
		cin >> data;
		answer = data[0];
		for (int i = 1; i < data.length(); i++) {
			if (data[i] != data[i - 1]) {
				answer += data[i];
			}
		}
		cout << answer << "\n";
	}
	return 0;
}