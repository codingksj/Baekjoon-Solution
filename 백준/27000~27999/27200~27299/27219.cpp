#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
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
	int N;
	string ans = "";
	cin >> N;
	for (int i = 0; i < N / 5; i++) {
		ans += "V";
	}
	for (int i = 0; i < N % 5; i++) {
		ans += "I";
	}
	cout << ans;
	return 0;
}