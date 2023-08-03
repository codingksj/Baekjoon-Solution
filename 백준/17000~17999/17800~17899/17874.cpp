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

	LL N, H, V;
	LL maxH, maxV;
	cin >> N >> H >> V;
	maxH = 2 * H > N ? H : N - H;
	maxV = 2 * V > N ? V : N - V;
	LL volume = 4 * maxH * maxV;
	cout << volume;
	return 0;
}