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
	int alpha_count[26] = { 0, };
	int pos;
	char word[101];
	cin >> word;
	for (int i = 0; word[i] != '\0'; i++) {
		pos = word[i] - 'a';
		alpha_count[pos]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha_count[i] << " ";
	}
	return 0;
}