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
	
	double a, b, c, d;
	double rotation[4];
	double maxV = 0.0;

	cin >> a >> b >> c >> d;
	rotation[0] = a / c + b / d;
	rotation[1] = c / d + a / b;
	rotation[2] = d / b + c / a;
	rotation[3] = b / a + d / c;
	for (int i = 0; i < 4; i++) {
		if (maxV < rotation[i]) {
			maxV = rotation[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (maxV == rotation[i]) {
			cout << i;
			break;
		}
	}

	return 0;
}