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
	int N, A, B;
	cin >> N >> A >> B;
	if (A < B) {
		cout << "Bus" << "\n";
	}
	else if (A > B) {
		cout << "Subway" << "\n";
	}
	else {
		cout << "Anything" << "\n";
	}
	return 0;
}