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
	int TC, length;
	char S[22];
	cin >> TC;
	while (TC--) {
		cin >> S;
		length = strlen(S);
		((length >= 6) && (length <= 9)) ? cout << "yes\n" : cout << "no\n";
	}
	return 0;
}