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

char MyUpper(char c);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string line;
	char c;
	char upperC, upperAlpha;
	int count;

	while (true) {
		cin >> c;
		if (c == '#') {
			break;
		}
		getline(cin, line);
		count = 0;
		upperC = MyUpper(c);
		for (auto alpha : line) {
			upperAlpha = MyUpper(alpha);
			if (upperC == upperAlpha) {
				count++;
			}
		}
		cout << c << " " << count << "\n";
	}

	return 0;
}

char MyUpper(char c) {
	char letter = c;
	if (letter >= 'a' && letter <= 'z') {
		letter += ('A' - 'a');
	}
	return letter;
};

