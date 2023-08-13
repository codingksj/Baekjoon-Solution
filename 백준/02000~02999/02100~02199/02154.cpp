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


int FindFirstAppearance(int N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	cin >> N;
	cout << FindFirstAppearance(N) << "\n";

	return 0;
}

int FindFirstAppearance(int N) {
	string concat_num = "";
	string target = to_string(N);
	int index;

	for (int i = 1; i <= N; i++) {
		concat_num += to_string(i);
	}
	index = concat_num.find(target);
	return (index + 1);
};
