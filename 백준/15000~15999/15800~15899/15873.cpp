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

	int N;
	int A, B;
	cin >> N;
	if (N < 110) {
		A = N / 10;
		B = N % 10;
	}
	else if (N < 911) {
		A = N / 100;
		B = N - A * 100;
	}
	else {
		A = 10;
		B = 10;
	}
	cout << A + B;
	return 0;
}