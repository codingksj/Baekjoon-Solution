#include<iostream>
#include<sstream>
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
typedef pair<LL, LL> PLL;

string FixMisspelling(string word, int pos);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string word;
	int TC, pos;

	cin >> TC;

	while (TC--) {
		cin >> pos >> word;
		cout << FixMisspelling(word, pos) << "\n";
	}
	return 0;
}

string FixMisspelling(string word, int pos) {
	vector<char> V;
	string fixedWord;
	for (char letter : word) {
		V.push_back(letter);
	}
	V.erase(V.begin() + pos - 1);
	fixedWord = string(V.begin(), V.end());

	return fixedWord;
};