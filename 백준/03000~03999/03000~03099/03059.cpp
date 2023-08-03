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
	
	int TC, sum;
	set<char> alphabets;
	string S;

	cin >> TC;
	while (TC--) {
		alphabets.clear();
		sum = ('A' + 'Z') * 13;
		cin >> S;
		for (auto letter : S) {
			alphabets.insert(letter);
		}
		for (auto letter : alphabets) {
			sum -= letter;
		}
		cout << sum << "\n";
	}
	return 0;
}