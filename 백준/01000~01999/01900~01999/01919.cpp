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

int GetMinDeleteAlpha(string word1, string word2);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string word1, word2;

	getline(cin, word1);
	getline(cin, word2);

	cout << GetMinDeleteAlpha(word1, word2);

	return 0;
}

int GetMinDeleteAlpha(string word1, string word2) {
	int word1_alpha[26] = { 0, };
	int word2_alpha[26] = { 0, };
	int pos1, pos2, delta;
	int word1L = word1.length();
	int word2L = word2.length();
	int minDelete = 0;

	for (int i = 0; i < word1L; i++) {
		pos1 = word1[i] - 'a';
		word1_alpha[pos1]++;
	}

	for (int i = 0; i < word2L; i++) {
		pos2 = word2[i] - 'a';
		word2_alpha[pos2]++;
	}

	for (int i = 0; i < 26; i++) {
		delta = abs(word1_alpha[i] - word2_alpha[i]);
		minDelete += delta;
	}

	return minDelete;
};