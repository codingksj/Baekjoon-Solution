#include<iostream>
#include<set>
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

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numbers[2002] = { 0, };
	int TC, num;
	cin >> TC;
	while (TC--) {
		cin >> num;
		numbers[num + 1000]++;
	}
	for (int i = 0; i <= 2000; i++) {
		if (numbers[i] > 0) {
			cout << i - 1000 << " ";
		}
	}
	return 0;
}