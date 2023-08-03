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
	
	int A, I, fee;
	cin >> A >> I;
	for (fee = (I - 1) * A; fee <= I * A;fee++) {
		if (ceil((double)fee / A) == I) {
			cout << fee;
			break;
		}
	}

	return 0;
}