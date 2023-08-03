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

	int hole;
	int count8, count4;
	string answer="";
	
	cin >> hole;
	if (hole == 0) {
		answer += "1";
	}
	else if (hole == 1) {
		answer += "0";
	}
	else {
		count8 = hole / 2;
		count4 = hole % 2;
		answer += count4 ? "4" : "";
		while (count8--) {
			answer += "8";
		}
	}
	cout << answer;
	return 0;
}