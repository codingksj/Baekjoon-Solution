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

	int doll, notBedroom;
	int total_doll;
	int pairs, groups;

	while (true) {
		cin >> doll >> notBedroom;
		if (doll == 0 && notBedroom == 0) {
			break;
		}
		total_doll = doll - notBedroom;
		if (total_doll < 2) {
			pairs = 0;
			groups = 0;
		}
		else if (total_doll & 1) {
			pairs = (total_doll - 3) / 2;
			groups = 1;
		}
		else {
			pairs = total_doll / 2;
			groups = 0;
		}
		cout << pairs << " " << groups << "\n";
	}
	return 0;
}