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
	int antenna, eye;
	cin >> antenna >> eye;
	if (antenna >= 3 && eye <= 4) {
		cout << "TroyMartian" << "\n";
	}
	if (antenna <= 6 && eye >= 2) {
		cout << "VladSaturnian" << "\n";
	}
	if (antenna <= 2 && eye <= 3) {
		cout << "GraemeMercurian" << "\n";
	}
	return 0;
}