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
typedef pair<LL, LL> Pll;

LL CountSquare(int size);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	while (true) {
		cin >> size;
		if (size == 0) {
			break;
		}
		cout << CountSquare(size) << "\n";
	}
	return 0;
}

LL CountSquare(int N) {
	LL answer = 0;
	LL i, j;
	LL square;
	for (i = 1; i <= N; i++) {
		square = 0;
		for (j = i; j <= N; j++) {
			square++;
		}
		answer += (square * square);
	}
	return answer;
};


