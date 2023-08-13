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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

void FindSquareNumber(int N, int M);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	
	cin >> N >> M;

	FindSquareNumber(N, M);

	return 0;
}

void FindSquareNumber(int N, int M) {
	int start = ceil(sqrt(N));
	int end = floor(sqrt(M));

	int square;
	int sum = 0;
	int min = 10001;


	for (start; start <= end; start++) {
		square = start * start;
		if (square < min) {
			min = square;
		}
		sum += square;
	}

	if (sum) {
		cout << sum << "\n"
			<< min << "\n";
	}
	else {
		cout << -1;
	}

};