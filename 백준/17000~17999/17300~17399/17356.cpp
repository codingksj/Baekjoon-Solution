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
	int A, B;
	double M;
	double P;
	cin >> A >> B;
	M = (B - A) / 400.0;
	P = 1 / (1 + pow(10, M));
	cout.precision(16);
	cout << P;
	return 0;
}