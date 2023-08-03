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

	string address = "hello";
	int L;

	while (true) {
		getline(cin, address);
		L =  address.length() + 1;
	
		if (address == "0") {
			break;
		}
		for (auto digit : address) {
			if (digit == '1') {
				L += 2;
			}
			else if (digit == '0') {
				L += 4;
			}
			else {
				L += 3;
			}
		}
		cout << L << "\n";
	}


	return 0;
}