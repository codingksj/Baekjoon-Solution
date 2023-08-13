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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string line;
	int alphabets[26] = { 0, };
	int index, maxV;
	char c;

	while (getline(cin, line)) {
		for (auto letter : line) {
			if (letter < 'a' || letter > 'z') {
				continue;
			}
			index = letter - 'a';
			alphabets[index]++;
		}
	}

	maxV = alphabets[0];

	for (int i = 1; i < 26; i++) {
		if (alphabets[i] > maxV) {
			maxV = alphabets[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabets[i] == maxV) {
			c = 'a' + i;
			cout << c;
		}
	}

	return 0;
}

