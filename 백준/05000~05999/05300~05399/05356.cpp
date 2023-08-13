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

void PrintAlphaTriangle(int size, char alpha);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC, size;
	char alpha;

	cin >> TC;

	while (TC--) {
		cin >> size >> alpha;
		PrintAlphaTriangle(size, alpha);
	}
	return 0;
}

void PrintAlphaTriangle(int size, char alpha) {
	char curAlpha = alpha;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
			cout << curAlpha;
		}
		curAlpha = curAlpha < 'Z' ? curAlpha + 1 : 'A';
		cout << "\n";
	}
	cout << "\n";
}
