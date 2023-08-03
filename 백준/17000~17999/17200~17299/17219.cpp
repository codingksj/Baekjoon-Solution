#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string address, password;
	map<string, string> memo;
	cin >> N >> M;
	while (N--) {
		cin >> address >> password;
		memo[address] = password;
	}
	while (M--) {
		cin >> address;
		cout << memo[address] << "\n";
	}
	return 0;
}