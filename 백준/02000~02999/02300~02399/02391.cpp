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

int CalculateSimilarity(string& sacha_word, string& dict_word);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<string, int>> dictionary;
	string sacha_word, dict_word, answer;
	int TC, N;
	int similarity, maxSimilarity;

	cin >> TC;
	while (TC--) {
		dictionary.clear();
		cin >> sacha_word;
		cin >> N;
		while (N--) {
			cin >> dict_word;
			similarity = CalculateSimilarity(sacha_word, dict_word);
			dictionary.push_back({ dict_word, similarity });
		}
		maxSimilarity = -1;
		for (pair<string, int>& p : dictionary) {
			if (p.second > maxSimilarity) {
				maxSimilarity = p.second;
				answer = p.first;
			}
		}
		cout << answer << "\n";
	}


	return 0;
}


int CalculateSimilarity(string& sacha_word, string& dict_word) {
	int maxL = sacha_word.length();
	int similarity = 0;
	for (int i = 0; i < maxL; i++) {
		(sacha_word[i] == dict_word[i]) && similarity++;
	}
	return similarity;
};