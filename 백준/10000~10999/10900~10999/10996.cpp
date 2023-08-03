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

	string star1 = "* ";
	string star2 = " *";
	int N, up, down;

	cin >> N;
	for (int i = 0; i < N; i++) {
		up = N - N / 2;
		down = N / 2;
		for (int j = 0; j < up; j++) {
			cout << star1;
		}
		cout << "\n";
		for (int j = 0; j < down; j++) {
			cout << star2;
		}
		cout << "\n";
	}
	return 0;
}