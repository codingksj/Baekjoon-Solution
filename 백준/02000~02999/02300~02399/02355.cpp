#include<iostream>
#include<bitset>
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


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL A, B;

	cin >> A >> B;

	if (A > B) {
		swap(A, B);
	}

	cout << (A + B) * (B - A + 1) / 2;

	return 0;
}

