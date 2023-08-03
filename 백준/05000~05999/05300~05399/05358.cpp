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
	bool wrong;
	string name;
	map<char, char> Correct = {
		{'I','E'},
		{'E','I'},
		{'i','e'},
		{'e','i'}
	};
	while (getline(cin, name)) {
		for (char letter : name) {
			wrong = letter == 'i' || letter == 'e' || letter == 'I' || letter == 'E';
			if (!wrong) {
				cout << letter;
				continue;
			}
			cout << Correct[letter];
		}
		cout << "\n";
	}
	return 0;
}