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
	bool corrupted = false;
	int N[8];
	for (int i = 0; i < 8; i++) {
		cin >> N[i];
		if (N[i] == 9) {
			corrupted = true;
			break;
		}
	}
	corrupted ? cout << "F" : cout << "S";
	return 0;
}