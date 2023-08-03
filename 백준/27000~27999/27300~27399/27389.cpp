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
	int N;
	double answer;
	cin >> N;
	answer = N / 4.0;
	cout.setf(ios::fixed); cout.precision(2);
	cout << answer << "\n";
	return 0;
}